# Temporizador de Um Disparo (One Shot) - Raspberry Pi Pico W

## Descrição
Este projeto implementa um sistema de temporização para o acionamento de LEDs utilizando um botão (pushbutton) como gatilho. Após pressionar o botão, os LEDs acendem simultaneamente e, em seguida, desligam-se progressivamente com um atraso de 3 segundos entre cada mudança de estado.

## Componentes Utilizados
- Raspberry Pi Pico W
- 03 LEDs (Azul, Vermelho e Verde)
- 03 Resistores de 330 Ω
- 01 Botão (Pushbutton)
- **OBS: É possível realizar a atividade no BitDogLab**

## Funcionamento
1. Quando o botão for pressionado:
   - Todos os LEDs acendem simultaneamente.
   - Após 3 segundos, o LED vermelho apaga.
   - Após 6 segundos, o LED azul apaga.
   - Após 9 segundos, o LED verde apaga.
   - O botão só pode ser acionado novamente após todos os LEDs serem desligados.

## Requisitos
- Ambiente de desenvolvimento VS Code
- Pico SDK configurado
- Simulador Wokwi integrado ao VS Code

## Instalação e Uso
1. ```sh
   git clone https://github.com/Samir21203/Tarefa---U4C5.git
   cd Tarefa---U4C5
   cd U4C5_ATV2
   ```
2. Importe o projeto com o plugin *Raspberry Pi Pico Project* para VS Code.
3. Compile e execute o simulador Wokwi (se estiver testando virtualmente).
2. Compile o código com o Pico SDK.
3. Carregue o binário no BitDogLab (Se estiver utilizando).
4. Execute a simulação no Wokwi.

## Código-Fonte Principal
O código principal configura os pinos dos LEDs e do botão, além de utilizar `add_alarm_in_ms()` para gerenciar os atrasos entre as mudanças de estado dos LEDs.

## Observação
- O código inclui um mecanismo para evitar que o botão seja pressionado repetidamente enquanto os LEDs ainda estão no processo de desligamento.
- O sistema pode ser testado tanto no hardware real quanto no simulador Wokwi.

## Autor
Desenvolvido como parte da atividade prática para a disciplina de Microcontroladores.

