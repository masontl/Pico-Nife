String currentSerialNumber = "990636";  // Default serial number
String currentDOM = "01/01/2024";

void setup() {
  Serial.begin(57600);  // Initialize serial communication with a baud rate of 57600
}

void loop() {
  if (Serial.available()) {                         // Check if there's data available to read
    String command = Serial.readStringUntil('\n');  // Read the command until a newline character is encountered
    command.trim();                                 // Remove leading and trailing whitespaces

    // Convert the command to lowercase for case-insensitive comparison
    command.toLowerCase();

    if (command == "id?") {
      // Serial.println("Mensor 9414 Quad Controller SN 990636 F");
      Serial.print("MENSOR,MODEL 9250,");
      Serial.print(currentSerialNumber);
      Serial.println(",99.2.0");
    } else if (command == "#*id?") {
      Serial.println("5 ID   Mensor,     6110,   590455, V1.10");
    } else if (command == "ver?") {
      Serial.println("Version: 2.01");
    } else if (command == "gains?") {
      Serial.println("offset: 0.00100, 4.00000, 10.00000, -0.00050, -2.00000, -10.00000 mult: 25.0000");
    } else if (command == "setwindow?") {
      Serial.println("0.102");
    } else if (command == "xall?") {
      Serial.println("0, 0, 0, 0");
    } else if (command == "sn?") {
      Serial.println(currentSerialNumber);
    } else if (command == "dom?") {
      Serial.println(currentDOM);
    } else if (command.startsWith("mynum=")) {
      String newSerialNumber = command.substring(6);  // Extract serial number from command
      currentSerialNumber = newSerialNumber;          // Update the variable
      // Serial.println("Serial number updated.");
    } else if (command.startsWith("instsn ")) {
      String newSerialNumber = command.substring(7);  // Extract serial number from command
      currentSerialNumber = newSerialNumber;          // Update the variable
      // Serial.println("Serial number updated.");
    } else if (command.startsWith("instdom ")) {
      String newDOM = command.substring(8);  // Extract date number from command
      currentDOM = newDOM;                   // Update the variable
    } else if (command.startsWith("pass=#a ")) {
      if (command.endsWith("id?")) {
        Serial.println("A ID   MENSOR,     6100, 824903, V5.00");
      } else if (command.endsWith("sc?")) {
        Serial.println("A SC 1.000000");
      } else if (command.endsWith("zc?")) {
        Serial.println("A ZC 0.000000");
      } else if (command.endsWith("fs?")) {
        Serial.println("A FS 0.010");
      } else if (command.endsWith("u?")) {
        Serial.println("A U  1");
      } else if (command.endsWith("r-?")) {
        Serial.println("A R- 0.000000");
      } else if (command.endsWith("r+?")) {
        Serial.println("A R+ 300.000000");
      } else if (command.endsWith("dc?")) {
        Serial.println("A DC 033122");
      }
    } else if (command.startsWith("pass=#b ")) {
      if (command.endsWith("id?")) {
        Serial.println("B ID   MENSOR,     6100, 824901, V5.00");
      } else if (command.endsWith("sc?")) {
        Serial.println("B SC 1.000000");
      } else if (command.endsWith("zc?")) {
        Serial.println("B ZC 0.000000");
      } else if (command.endsWith("fs?")) {
        Serial.println("B FS 0.010");
      } else if (command.endsWith("u?")) {
        Serial.println("B U  1");
      } else if (command.endsWith("r-?")) {
        Serial.println("B R- 0.000000");
      } else if (command.endsWith("r+?")) {
        Serial.println("B R+ 300.000000");
      } else if (command.endsWith("dc?")) {
        Serial.println("B DC 033122");
      }
    } else if (command.startsWith("pass=#c ")) {
      if (command.endsWith("id?")) {
        Serial.println("C ID   MENSOR,     6100, 824904, V5.00");
      } else if (command.endsWith("sc?")) {
        Serial.println("C SC 1.000000");
      } else if (command.endsWith("zc?")) {
        Serial.println("C ZC 0.000000");
      } else if (command.endsWith("fs?")) {
        Serial.println("C FS 0.010");
      } else if (command.endsWith("u?")) {
        Serial.println("C U  1");
      } else if (command.endsWith("r-?")) {
        Serial.println("C R- 0.000000");
      } else if (command.endsWith("r+?")) {
        Serial.println("C R+ 300.000000");
      } else if (command.endsWith("dc?")) {
        Serial.println("C DC 033122");
      }
    } else if (command.startsWith("pass=#d ")) {
      if (command.endsWith("id?")) {
        Serial.println("D ID   MENSOR,     6100, 824902, V5.00");
      } else if (command.endsWith("sc?")) {
        Serial.println("D SC 1.000000");
      } else if (command.endsWith("zc?")) {
        Serial.println("D ZC 0.000000");
      } else if (command.endsWith("fs?")) {
        Serial.println("D FS 0.010");
      } else if (command.endsWith("u?")) {
        Serial.println("D U  1");
      } else if (command.endsWith("r-?")) {
        Serial.println("D R- 0.000000");
      } else if (command.endsWith("r+?")) {
        Serial.println("D R+ 300.000000");
      } else if (command.endsWith("dc?")) {
        Serial.println("D DC 033122");
      }
    } else {
      Serial.println("Unknown command");  // Respond with this message for unrecognized commands
    }
  }
}
