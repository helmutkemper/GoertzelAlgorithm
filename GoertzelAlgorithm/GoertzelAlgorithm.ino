float amostras[ 100 ];

void setup ()
{
  Serial.begin ( 19200 );    
}

void loop ()
{
  for ( int i = 0; i != 100; i++ )
  {
    amostras[ i ] = analogRead ( 0 );
    delay ( 8 );
  }
    
  for ( int i = 0; i != 100; i++ )
  {
    amostras[ i ] = 5.0f / 1024.0f * amostras[ i ];
  }
  
  Serial.println ( goertzel_mag ( 100, 60, 123, &amostras[0] ), DEC );
}

float goertzel_mag(int numSamples,int TARGET_FREQUENCY,int SAMPLING_RATE, float* data)
{
  int     k,i;
  float   floatnumSamples;
  float   omega,sine,cosine,coeff,q0,q1,q2,magnitude,real,imag;

  float   scalingFactor = numSamples / 2.0f;

  floatnumSamples = (float) numSamples;
  k = (int) (   0.5f +     ((floatnumSamples * TARGET_FREQUENCY) / SAMPLING_RATE));
  omega = (2.0f * M_PI * k) / floatnumSamples;
  sine = sin(omega);
  cosine = cos(omega);
  coeff = 2.0f * cosine;
  q0=0;
  q1=0;
  q2=0;

  for(i=0; i<numSamples; i++)
  {
    q0 = coeff * q1 - q2 + data[i];
    q2 = q1;
    q1 = q0;
  }

  // calculate the real and imaginary results
  // scaling appropriately
  real = (q1 - q2 * cosine) / scalingFactor;
  imag = (q2 * sine) / scalingFactor;

  magnitude = sqrt(real*real + imag*imag);
  return magnitude;
}
