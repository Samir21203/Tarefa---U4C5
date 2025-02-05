# Semáforo com Raspberry Pi Pico W

Este projeto implementa um semáforo utilizando o microcontrolador **Raspberry Pi Pico W** e a ferramenta **Pico SDK**. O código alterna entre os estados do semáforo (vermelho, amarelo e verde) a cada **3 segundos** e exibe mensagens pela porta serial a cada **1 segundo**.

## 🚀 Requisitos
- Raspberry Pi Pico W
- 3 LEDs (vermelho, amarelo e verde) ou um LED RGB
- 3 resistores de 330 Ω
- Ambiente de desenvolvimento VS Code
- Pico SDK instalado
- Simulador Wokwi configurado no VS Code
- GitHub para versionamento
- **OBS: Com a placa BitDogLab é possível executar a atividade.**

## 📜 Como Funciona
1. O semáforo inicia com o **LED vermelho aceso**.
2. A cada **3 segundos**, o semáforo alterna para o próximo estado:
   - Vermelho → Amarelo → Verde → Vermelho ...
3. O estado atual é impresso na porta serial a cada **1 segundo**.
4. A mudança de estado é controlada por um temporizador repetitivo usando `add_repeating_timer_ms()`.

## 📥 Instalação e Execução
1. Clone o repositório:
   ```sh
   git clone https://github.com/seu-usuario/semaforo-pico.git
   cd semaforo-pico
   ```
2. Compile e carregue o código no Raspberry Pi Pico W:
   ```sh
   mkdir build && cd build
   cmake ..
   make
   ```
3. Execute o simulador Wokwi (se estiver testando virtualmente).

## 📌 Pinos Utilizados
| Componente  | GPIO |
|------------|------|
| LED Vermelho | 11 |
| LED Amarelo | 12 |
| LED Verde | 13 |

## 🔍 Testes e Debugging
- Utilize um monitor serial (`minicom`, `PuTTY`, `screen`) para visualizar as mensagens.
- Certifique-se de que os LEDs estão conectados corretamente.
- Modifique os tempos no código para testar diferentes intervalos.

## 📜 Licença
Este projeto é de livre uso para fins educacionais. 😊

