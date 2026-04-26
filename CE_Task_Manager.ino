/* The intent of this program is to explore how to do asynchronous
non-blocking programming by implementing a polled and round-robin 
cyclic executive task manager based upon a function pointer array. 
To this end, this program queries the user across the serial port 
what LED and what interval should that LED blink with. There are 2 
LEDs, and each LED can blink at different rates. The user can change
the blink rates of one LED independent of the other.
Who: Amrita Shrestha
When: November 11, 2025
*/

// Defines which LED corresponds to a certain pin
const int led1 = 3;
const int led2 = 2;

// Sets the initial blinking interval for each LED when connected to power
// in milliseconds
unsigned long interval1 = 1000;
unsigned long interval2 = 1000;

// Stores the previous blinking time/last updated time of each LED
unsigned long prevTime1 = 0;
unsigned long prevTime2 = 0;

// Sets boolean flags for each LED state
bool ledState1 = LOW;
bool ledState2 = LOW;

// Stores user input from Serial Monitor
String userInput = "";
bool waitingForLED = true;
int currLED = 0;

// Function declarations for each task, such as handling the LEDs and serial monitor user input
void taskHandleBlinkLED1();
void taskHandleBlinkLED2();
void taskHandleSerialMonitor();

// Defines the function pointer array to manage round-robin cyclic executive tasks
typedef void (*TaskFunc)();
TaskFunc taskList[] = {taskHandleBlinkLED1, taskHandleBlinkLED2, taskHandleSerialMonitor};
const int NUM_TASKS = sizeof(taskList) / sizeof(TaskFunc);

void setup() {
  // Sets the corresponding LED as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);

  // Prompts user to enter which LED to adjust its blinking interval
  Serial.println("Which LED? (1 or 2)");
}

// Defines the cyclic executive loop
void loop() {
  // Executes all tasks in round-robin order by calling each task
  for (int i = 0; i < NUM_TASKS; i++) {
    taskList[i]();
  }
}

// Task that handles the blinking interval for LED1
void taskHandleBlinkLED1() {
  // Returns the number of milliseconds since the board began running
  unsigned long currTime = millis();

  if (currTime - prevTime1 >= interval1) {
    prevTime1 = currTime;
    ledState1 = !ledState1;
    digitalWrite(led1, ledState1);
  }
}

// Task that handles the blinking interval for LED2
void taskHandleBlinkLED2() {
  // Returns the number of milliseconds since the board began running
  unsigned long currTime = millis();

  if (currTime - prevTime2 >= interval2) {
    prevTime2 = currTime;
    ledState2 = !ledState2;
    digitalWrite(led2, ledState2);
  }
}

// Task that handles the user inputs from the Serial Monitor
void taskHandleSerialMonitor() {
  // Processes user input if there is a serial monitor input available
  if (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      userInput.trim();

      // Expects the user to enter an LED selection (either 1 or 2)
      if (waitingForLED) {
        currLED = userInput.toInt();
        // If the appropriate LED selection is entered, then prompt which blinking interval to set
        if (currLED == 1 || currLED == 2) {
          Serial.println("What interval (in msec)? ");
          waitingForLED = false;

          // If user does not enter a valid number for the blinking interval,
          // then prompt a warning message to reenter LED selection.
        } else {
          Serial.println("Invalid LED. Choose 1 or 2.");
          Serial.println("Which LED? (1 or 2)");
        }
      }
      else {
        // Expects the user to enter an blinking interval (a number greater than 0)
        unsigned long interval = userInput.toInt();
        if (interval > 0) {
          if (currLED == 1) {
            interval1 = interval;
            Serial.println("LED1 interval set to " + String(interval1) + " ms");
          } else if (currLED == 2) {
            interval2 = interval;
            Serial.println("LED2 interval set to " + String(interval2) + " ms");
          }
        } else {
          Serial.println("Invalid interval. Please enter a number > 0.");
        }

        waitingForLED = true;
        Serial.println("Which LED? (1 or 2)");
      }
      // Clears input string for the next input
      userInput = ""; // Reset input buffer
    } 
    // Appends the next user input to userInput
    else {
      userInput += inChar;
    }
  }
}