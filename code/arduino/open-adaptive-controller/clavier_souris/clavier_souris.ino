/*
   Open Adaptive Controller
   My Human Kit 2020

   Compatible Arduino Leonardo uniquement.

   Émule une souris (clic gauche et clic droit)
   et un clavier :
    - touches 'a' à 'h'
    - touches 'espace', 'entrée', 'ctrl', 'shift'
    - touches 'fleches'
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

Button boutonClicDroit(HIGH, 2);
Button boutonClicGauche(HIGH, 3);

Button boutonA(HIGH, 4);
Button boutonB(HIGH, 5);
Button boutonC(HIGH, 6);
Button boutonD(HIGH, 7);
Button boutonE(HIGH, 8);
Button boutonF(HIGH, 9);
Button boutonG(HIGH, 10);
Button boutonH(HIGH, 11);

Button boutonEspace(HIGH, 12);
Button boutonEntree(HIGH, 13);

Button boutonCtrl(HIGH, A0);
Button boutonShift(HIGH, A1);

Button boutonGauche(HIGH, A2);
Button boutonHaut(HIGH, A3);
Button boutonBas(HIGH, A4);
Button boutonDroit(HIGH, A5);


void setup() {
  //pinMode(LED, OUTPUT);

  boutonClicDroit.init();
  boutonClicGauche.init();

  boutonA.init();
  boutonB.init();
  boutonC.init();
  boutonD.init();
  boutonE.init();
  boutonF.init();
  boutonG.init();
  boutonH.init();

  boutonEspace.init();
  boutonEntree.init();

  boutonCtrl.init();
  boutonShift.init();

  boutonGauche.init();
  boutonHaut.init();
  boutonBas.init();
  boutonDroit.init();

  Mouse.begin();
  Keyboard.begin();
}

void loop() {
  boutonClicDroit.read();
  boutonClicGauche.read();

  boutonA.read();
  boutonB.read();
  boutonC.read();
  boutonD.read();
  boutonE.read();
  boutonF.read();
  boutonG.read();
  boutonH.read();

  boutonEspace.read();
  boutonEntree.read();

  boutonCtrl.read();
  boutonShift.read();

  boutonGauche.read();
  boutonHaut.read();
  boutonBas.read();
  boutonDroit.read();


  if (boutonClicDroit.isJustPressed()) {
    Mouse.press(MOUSE_RIGHT);
  }
  if (boutonClicDroit.isJustReleased()) {
    Mouse.release(MOUSE_RIGHT);
  }

  if (boutonClicGauche.isJustPressed()) {
    Mouse.press(MOUSE_LEFT);
  }
  if (boutonClicGauche.isJustReleased()) {
    Mouse.release(MOUSE_LEFT);
  }


  if (boutonA.isJustPressed()) {
    Keyboard.press('a');
  }

  if (boutonA.isJustReleased()) {
    Keyboard.release('a');
  }

  if (boutonB.isJustPressed()) {
    Keyboard.press('b');
  }

  if (boutonB.isJustReleased()) {
    Keyboard.release('b');
  }

  if (boutonC.isJustPressed()) {
    Keyboard.press('c');
  }

  if (boutonC.isJustReleased()) {
    Keyboard.release('c');
  }

  if (boutonD.isJustPressed()) {
    Keyboard.press('d');
  }

  if (boutonD.isJustReleased()) {
    Keyboard.release('d');
  }

  if (boutonE.isJustPressed()) {
    Keyboard.press('e');
  }

  if (boutonE.isJustReleased()) {
    Keyboard.release('e');
  }

  if (boutonF.isJustPressed()) {
    Keyboard.press('f');
  }

  if (boutonF.isJustReleased()) {
    Keyboard.release('f');
  }

  if (boutonG.isJustPressed()) {
    Keyboard.press('g');
  }

  if (boutonG.isJustReleased()) {
    Keyboard.release('g');
  }

  if (boutonH.isJustPressed()) {
    Keyboard.press('h');
  }

  if (boutonH.isJustReleased()) {
    Keyboard.release('h');
  }


  if (boutonEspace.isJustPressed()) {
    Keyboard.press(KEY_BACKSPACE);
  }

  if (boutonEspace.isJustReleased()) {
    Keyboard.release(KEY_BACKSPACE);
  }

  if (boutonEntree.isJustPressed()) {
    Keyboard.press(KEY_RETURN);
  }

  if (boutonEntree.isJustReleased()) {
    Keyboard.release(KEY_RETURN);
  }


  if (boutonCtrl.isJustPressed()) {
    Keyboard.press(KEY_LEFT_CTRL);
  }

  if (boutonCtrl.isJustReleased()) {
    Keyboard.release(KEY_LEFT_CTRL);
  }

  if (boutonShift.isJustPressed()) {
    Keyboard.press(KEY_LEFT_SHIFT);
  }

  if (boutonShift.isJustReleased()) {
    Keyboard.release(KEY_LEFT_SHIFT);
  }



  if (boutonGauche.isJustPressed()) {
    Keyboard.press(KEY_LEFT_ARROW);
  }

  if (boutonGauche.isJustReleased()) {
    Keyboard.release(KEY_LEFT_ARROW);
  }

  if (boutonHaut.isJustPressed()) {
    Keyboard.press(KEY_UP_ARROW);
  }

  if (boutonHaut.isJustReleased()) {
    Keyboard.release(KEY_UP_ARROW);
  }

  if (boutonBas.isJustPressed()) {
    Keyboard.press(KEY_DOWN_ARROW);
  }

  if (boutonBas.isJustReleased()) {
    Keyboard.release(KEY_DOWN_ARROW);
  }

  if (boutonDroit.isJustPressed()) {
    Keyboard.press(KEY_RIGHT_ARROW);
  }

  if (boutonDroit.isJustReleased()) {
    Keyboard.release(KEY_RIGHT_ARROW);
  }



  delay(10);
}
