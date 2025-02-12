🔐 Password-Based Security System using PIC16F877A

📌 Overview

This project is a password-protected security system using a PIC16F877A microcontroller, 4x4 keypad, and 16x2 LCD display. It allows users to enter a password via the keypad, verifies it, and provides feedback through an LED or buzzer.

🌟 Features

🔢 4x4 Keypad Input Handling: Detects key presses and displays them on the LCD.

🔑 Password Verification: Compares the entered password with a predefined one.

📟 LCD Display: Guides the user with messages like "Enter Password" and "Password Correct/Incorrect."

🔔 LED/Buzzer Feedback: Provides an alert when the correct password is entered.

🛠 Proteus Simulation: Includes Proteus files for circuit simulation.

🔧 Components Used

🎛 PIC16F877A Microcontroller

🔢 4x4 Keypad

📟 16x2 LCD Display

💡 LED/Buzzer for feedback

🛠 Resistors, Capacitors, and Jumper Wires

⏳ 4MHz Crystal Oscillator

🏗 How It Works

📢 The system prompts the user to enter a 4-digit password.

⌨️ The user inputs the password via the 4x4 keypad.

🔍 The system verifies the entered password:

✅ If correct, it activates an output (LED/buzzer) and displays "Password Correct."

❌ If incorrect, it displays "Password Incorrect" and resets for a new attempt.

🔄 The system runs in a loop, allowing multiple attempts.

💻 Software & Tools

🖥 CCS C Compiler (for programming the PIC)

⚙️ Proteus (for circuit simulation)

🛠 Simulation & Testing

🏗 Open the Proteus file and load the HEX code into the PIC16F877A microcontroller.

▶️ Run the simulation to test the keypad input and password verification.

🔊 Observe the LCD messages and LED/buzzer response based on the password input.

🎯 Usage

This system can be used for:

🚪 Basic security applications (e.g., door locks, access control systems, authentication mechanisms).

🏡 Home automation security.

🏢 Office access control.

📂 Files Included

📜 Source Code (.c file)

🎛 Proteus Simulation Files (.dsn)

📥 HEX File (for direct upload to PIC)
