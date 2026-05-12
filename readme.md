# P.I.C.O. N.I.F.E. 
### (Portable Interface & Communication Operator)
**Industrial-grade handheld tool designed for high-reliability device address setting and communication.**

---

## 📺 Project Demonstration
Watch the Pico Nife scrolling through text in a human-readable way.

![Pico Nife in Action](Pictures/LCD_Scrolling_Video.mp4)

---

## 🛠 Hardware & Simulation Gallery

### Physical Build
| Completed Units | Interface Cable | Backlit 20x4 LCD Screen  |
| :---: | :---: | :---: |
| ![Unit](Pictures/PXL_20240226_121039711.MP.jpg) | ![Interface](Pictures/PXL_20240226_120728440.MP.jpg) | ![Internals](Pictures/PXL_20240226_120741423.MP.jpg) |
| *Final Assembly* | *DB9 Serial cable for M and F connections* | *RP2040 Integration and LCD initial menu screen* |

### Digital Twin & Logic Verification (SimulIDE)
| Circuit Layout | Recieving Info from Transducer | Use Case of Lack of Return Communication | SN and Date Setting Interface |
| :---: | :---: | :---: | :---: |
| ![Circuit](Screenshots/simulIDE/croppedScreenshot%20(22).png) | ![Logic](Screenshots/simulIDE/croppedScreenshot%20(26).png) | ![Serial](Screenshots/simulIDE/croppedScreenshot%20(27).png) | ![Path](Screenshots/simulIDE/croppedScreenshot%20(39).png) |

---

## 🧠 Engineering Highlight: Safety Interlocks
One of the core challenges was managing the **12VDC rail** required for transducers without risking damage to 5V models. I implemented a firmware-controlled **high-side switch** using a PNP transistor.

```cpp
// Safety Logic: The 12VDC buck converter is only energized 
// when the specific "Transducer" menu is active.
#define XDCR_PWR_ON HIGH
#define XDCR_PWR_OFF LOW
#define XDCR_PWR_PIN 22

void setup() {
  pinMode(XDCR_PWR_PIN, OUTPUT);
  digitalWrite(XDCR_PWR_PIN, XDCR_PWR_OFF); // Default to Safe/Off
}
