# Goertzel Algorithm

Em um determinado projeto, sempre que havia falha mecânica no acoplamento dos cabos, apareceria a interferência dos 60Hz da rede,
e surgiu a ideia de criar um alarme sempre que houvesse problemas com o cabo. Para isto, nós necessitávamos saber se era possível
medir a simples presença da frequência de 60Hz no cabo usando Arduino, ou qualquer outra plataforma barata, de modo a não 
interferir no projeto original.

Este repositório contém o código de teste e o gráfico com a resposta.

Para quem não está familiarizado com o algoritmo, ele é uma simplificação da transformada de Fourier, onde você informa a 
frequência desejada e ele devolve a intensidade da mesma.

![Máxima x Frequência](https://github.com/helmutkemper/GoertzelAlgorithm/blob/master/grafico_de_saida.png "Máxima x Frequência")

**Nota:** não tente fazer DTMF com o Arduino, o ADC tem taxas de amostragens muito lentas para as frequências acima de 60Hz.
