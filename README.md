# mahadevprasad-sahyadri-ECE
# TASK 5
# Half Subtractor Using VSDSquadron Mini (CH32V003F4U6)

This project implements a **half subtractor** using the **VSDSquadron Mini** (CH32V003F4U6 RISC-V MCU). The circuit computes the **difference (D)** and **borrow (B)** for two binary inputs.

## **Logic Equations**

- **Difference (D) = A ⊕ B** (XOR gate)
- **Borrow (B) = A' · B** (A NOT AND B)

## **Required Components**

- **VSDSquadron Mini (CH32V003F4U6)**
- **2 Push Buttons** (Inputs: A, B)
- **2 LEDs** (Outputs: Difference, Borrow)
- **3 Pull-down Resistors (10kΩ)** (For push buttons)
- **2 Current Limiting Resistors (220Ω - 1kΩ)** (For LEDs)
- **Jumper Wires**
- **Breadboard** (Optional)

## **Pin Assignments**

| **Component**              | **VSDSquadron Mini Pin** |
| -------------------------- | ------------------------ |
| **Push Button A**          | PD0                      |
| **Push Button B**          | PD1                      |
| **LED for Difference (D)** | PD2                      |
| **LED for Borrow (B)**     | PD3                      |

## **Wiring Instructions**

1. **Push Buttons (A, B, Reset)**

   - Connect **one side of each button to 3.3V**.
   - Connect the **other side of A to PD0, B to PD1**
   - Use **10kΩ resistors** to pull-down PD0 and PD1 **GND**.

2. **LED Outputs (D, B)**

   - Connect the **Anode (+) of LED for D to PD2**.
   - Connect the **Anode (+) of LED for B to PD3**.
   - Connect the **Cathodes (-) to GND via 220Ω resistors**.
     

## **Expected LED Outputs**

| **A**             | **B**   | **Difference (D) LED** | **Borrow (B) LED** |
| ----------------- | ------- | ---------------------- | ------------------ |
| 0                 | 0       | OFF                    | OFF                |
| 0                 | 1       | ON                     | ON                 |
| 1                 | 0       | ON                     | OFF                |
| 1                 | 1       | OFF                    | OFF                |

