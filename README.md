# ESP32-Embedded-System-Humidity-Sensor
Here's a **detailed GitHub README** for your ESP32-based **Humidity & Temperature Monitoring System**. This README includes setup instructions, wiring details, and usage information. 🚀  

---

## **🌡 ESP32 Humidity & Temperature Monitoring System**
A project using the **ESP32 Dev Kit**, **DHT22 sensor**, **RGB LED**, **buzzer**, and a **slide switch** to monitor humidity and temperature, providing **visual and audible alerts**.

### **📌 Features**
✔ **Monitors temperature & humidity** using a **DHT22 sensor**  
✔ **RGB LED** indicates humidity levels with different colors  
✔ **Buzzer alerts users** when humidity crosses a threshold  
✔ **Slide switch toggles LED state** between **Cyan** (Right) and **OFF** (Left)  
✔ **Internal pull-up configuration** for the slide switch  

---

## **📸 Project Overview**
![Project Diagram](your_image_link_here)  
_A visual representation of the ESP32 circuit._
WILL COME SOON!
---

## **🛠 Hardware & Components**
| Component | Description | ESP32 Pin |
|-----------|-------------|------------|
| **ESP32 Dev Kit V1** | Main microcontroller | — |
| **DHT22 Sensor** | Measures temperature & humidity | Data → GPIO 4 |
| **RGB LED** | Visual indication of humidity | R → GPIO 15, G → GPIO 2, B → GPIO 13 |
| **Buzzer** | Sounds an alert for high humidity | GPIO 5 |
| **Slide Switch** | Manually toggles RGB LED | GPIO 12 |
| **10kΩ Resistor** | Pull-down resistor for switch | Between GPIO 12 and GND |

---

## **🖥️ Installation & Setup**
### **1️⃣ Clone This Repository**
```sh
git clone https://github.com/yourusername/ESP32-Humidity-Monitor.git
cd ESP32-Humidity-Monitor
```

### **2️⃣ Install Dependencies**
Make sure you have the **Arduino IDE** and install the following libraries:
1. Open **Arduino IDE**
2. Go to **Library Manager** (`Sketch` → `Include Library` → `Manage Libraries`)
3. Install:
   - **DHT Sensor Library**
   - **Adafruit Unified Sensor**

### **3️⃣ Upload Code to ESP32**
1. Open `sketch.ino` in **Arduino IDE**.
2. Select the **ESP32 Dev Module** board (`Tools` → `Board` → `ESP32 Dev Module`).
3. Connect your ESP32 via USB.
4. Click **Upload** (✅).

---

## **⚡ Wiring Diagram**
Here’s how you should connect the components:

### **🔹 DHT22 Sensor**
| Pin | Connection |
|------|------------|
| **VCC** | **3.3V** |
| **GND** | **GND** |
| **Data (SDA)** | **GPIO 4** |

### **🔹 RGB LED**
| Pin | Connection |
|------|------------|
| **R (Red)** | **GPIO 15** |
| **G (Green)** | **GPIO 2** |
| **B (Blue)** | **GPIO 13** |
| **COM (Common Cathode)** | **GND** |

### **🔹 Buzzer**
| Pin | Connection |
|------|------------|
| **+ (Positive)** | **GPIO 5** |
| **- (Negative)** | **GND** |

### **🔹 Slide Switch**
| Pin | Connection |
|------|------------|
| **One Side** | **3.3V** |
| **Other Side** | **GPIO 12** |
| **10kΩ Resistor** | **Between GPIO 12 and GND** |

---

## **🚀 How It Works**
### **🔹 Humidity-Based RGB LED Colors**
- **30% - 40%** → **White**
- **40% - 50%** → **Blue**
- **50% - 60%** → **Green**
- **60% - 70%** → **Yellow**
- **70% - 80%** → **Orange**
- **80% - 90%** → **Red**
- **90% - 100%** → **Purple**

### **🔹 Slide Switch Behavior**
- **Move RIGHT → LED turns Cyan** 🟦  
- **Move LEFT → LED turns OFF (Black)** ⚫  

### **🔹 Buzzer Alerts**
- **Activates** when humidity **exceeds 80%** 🚨  
- **Silent** when humidity is below threshold 🔇  

---

## **🖥️ Serial Monitor Output**
Example output from the ESP32:
```sh
📊 Humidity: 75.5%  🌡 Temperature: 27.5°C
🟠 RGB LED: Orange (70% - 80%)
🔇 Buzzer off
⚫ RGB LED: Black (Switch Left)
🟦 RGB LED: Cyan (Switch Right)
```

---


## **📌 Contributing**
This is an individual project, pull requests and changes are **not** permitted.

---

## **📞 Contact**
📧 **Email:** lyndenfenn@gmail.com   
🔗 **GitHub:** [lf21aaj](https://github.com/lf21aaj)  

---

