/*
   Open Adaptive Controller
   My Human Kit 2020

   Compatible Arduino Leonardo uniquement.

   Émule une souris (clic gauche et clic droit)
   et un clavier (touches 'a' à 'h').
*/


#include "Keyboard.h"
#include "Mouse.h"

#define LED 13

class Button {
  public:
    // contructeur
    Button(int defaultValue = 0, int pin = 0) { // valeur par défaut, broche
      this->pin = pin;
      this->value = defaultValue;
      this->previousValue = defaultValue;
      this->defaultValue = defaultValue;
    };

    // accesseurs et mutateurs
    int get() {
      return value;
    };
    void set(int value) {
      this->previousValue = this->value;
      this->value = value;
    };

    //autres fonctions
    void init() {
      pinMode(pin, INPUT_PULLUP);
    };
    int read() {
      set(digitalRead(pin));
      return value;
    };
    bool isPressed() {
      return (value != defaultValue);
    };
    bool isReleased() {
      return (value == defaultValue);
    };
    bool hasChanged() {
      return (value != previousValue);
    };
    bool isJustPressed() {
      return (hasChanged() && isPressed());
    };
    bool isJustReleased() {
      return (hasChanged() && isReleased());
    };

  private:
    int pin;
    int value;
    int previousValue;
    int defaultValue;
};

Button boutonA(HIGH, 2);
Button boutonB(HIGH, 3);
Button boutonC(HIGH, 4);
Button boutonD(HIGH, 5);
Button boutonE(HIGH, 6);
Button boutonF(HIGH, 7);
Button boutonG(HIGH, 8);
Button boutonH(HIGH, 9);
Button boutonI(HIGH, 10);
Button boutonJ(HIGH, 11);

void setup() {
  pinMode(LED, OUTPUT);

  boutonA.init();
  boutonB.init();
  boutonC.init();
  boutonD.init();
  boutonE.init();
  boutonF.init();
  boutonG.init();
  boutonH.init();
  boutonI.init();
  boutonJ.init();

  Mouse.begin();
  Keyboard.begin();
}

void loop() {
  boutonA.read();
  boutonB.read();
  boutonC.read();
  boutonD.read();
  boutonE.read();
  boutonF.read();
  boutonG.read();
  boutonH.read();
  boutonI.read();
  boutonJ.read();

  if (boutonA.isJustPressed()) {
    Mouse.press(MOUSE_RIGHT);
  }
  if (boutonA.isJustReleased()) {
    Mouse.release(MOUSE_RIGHT);
  }

  if (boutonB.isJustPressed()) {
    Mouse.press(MOUSE_LEFT);
  }
  if (boutonB.isJustReleased()) {
    Mouse.release(MOUSE_LEFT);
  }

  if (boutonC.isJustPressed()) {
    Keyboard.press('a');
  }

  if (boutonC.isJustReleased()) {
    Keyboard.release('a');
  }

  if (boutonD.isJustPressed()) {
    Keyboard.press('b');
  }

  if (boutonD.isJustReleased()) {
    Keyboard.release('b');
  }

  if (boutonE.isJustPressed()) {
    Keyboard.press('c');
  }

  if (boutonE.isJustReleased()) {
    Keyboard.release('c');
  }

  if (boutonF.isJustPressed()) {
    Keyboard.press('d');
  }

  if (boutonF.isJustReleased()) {
    Keyboard.release('d');
  }

  if (boutonG.isJustPressed()) {
    Keyboard.press('e');
  }

  if (boutonG.isJustReleased()) {
    Keyboard.release('e');
  }

  if (boutonH.isJustPressed()) {
    Keyboard.press('f');
  }

  if (boutonH.isJustReleased()) {
    Keyboard.release('f');
  }

  if (boutonI.isJustPressed()) {
    Keyboard.press('g');
  }

  if (boutonI.isJustReleased()) {
    Keyboard.release('g');
  }

  if (boutonJ.isJustPressed()) {
    Keyboard.press('h');
  }

  if (boutonJ.isJustReleased()) {
    Keyboard.release('h');
  }
  delay(10);
}
