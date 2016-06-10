#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // 0x27 er i2c adressen
LiquidCrystal lcd2 (45, 44, 41, 40, 39, 38);

// SPØRSMÅL
String norskLett1[] = {"Hvilket ord", "rimer paa nese?", "finger", "lese", "hes"};
String norskLett2[] = {"Bilene kjorer", "paa ...", "veien", "skyene", "stadion"};
String norskLett3[] = {"Har en sau", "horn?", "ja", "nei", "bare om vinteren"};
String norskLett4[] = {"Kommer 'A'", "foran 'B'", "i alfabetet?", "nei", "av og til", "ja"};
String norskLett5[] = {"Hvor mange", "farger har", "Norges flagg?", "2", "3", "4"};
String norskVanskelig1[] = {"Genseren til", "Henrik var", "hest", "gul", "bord"};
String norskVanskelig2[] = {"Hvilket ord", "rimer paa kant?", "slant", "brev", "brennesle"};
String norskVanskelig3[] = {"Hva spiser", "en bever?", "gress", "fisk", "bark"};
String norskVanskelig4[] = {"Hva er", "en bil?", "fremkomstmiddel", "to-hjuling", "tre-hjuling"};
String norskVanskelig5[] = {"Hvilken bokstav", "kommer etter 'D'", "i alfabetet?", "C", "E", "F"};

String engelskLett1[] = {"Hva betyr", "ordet 'Horse' ?", "hoppe", "ku", "hest"};
String engelskLett2[] = {"Hva betyr", "ordet 'Summer' ?", "sommer", "vinter", "summen"};
String engelskLett3[] = {"Hva betyr", "ordet 'hat'?", "sko", "hatt", "katt"};
String engelskLett4[] = {"Hva betyr", "ordet 'jacket'?", "jakke", "genser", "bukse"};
String engelskLett5[] = {"Hva betyr", "ordet 'shoe'?", "shorts", "sko", "genser"};
String engelskVanskelig1[] = {"Hva finner du", "paa en 'Farm' ?", "race car", "traktor", "plane"};
String engelskVanskelig2[] = {"A plane is", "in the ...", "sun", "skies", "stairs"};
String engelskVanskelig3[] = {"Hva er det", "engelske ordet", "for 'hansker'?", "pants", "mittens", "hat"};
String engelskVanskelig4[] = {"Hva er det", "engelske ordet", "for 'spill'?", "food", "tuesday", "game"};
String engelskVanskelig5[] = {"What is", "a dog?", "hest", "hund", "ku"};

String samfunnLett1[] = {"Hva heter", "kongen av Norge?", "Thomas", "Harald", "Geir"};
String samfunnLett2[] = {"Hva er hoved-", "sted i Norge?", "Bergen", "Oslo", "Trondheim"};
String samfunnLett3[] = {"Hva er en", "bunad?", "bok", "fest-antrekk", "smykke"};
String samfunnLett4[] = {"Har Norge", "mange fjell?", "nei", "bare i Oslo", "ja"};
String samfunnLett5[] = {"Hva er en", "fjord?", "hest", "fjell", "vann"};
String samfunnVanskelig1[] = {"Hva er hoved-", "stad i Tyskland?", "Kiel", "Munchen", "Berlin"};
String samfunnVanskelig2[] = {"Hvem er Norges", "statsminister?", "Jens", "Tor Arve", "Erna"};
String samfunnVanskelig3[] = {"Hvorfor feirer", "vi 17.mai?", "Kongens bursdag", "grunnloven", "snart sommer"};
String samfunnVanskelig4[] = {"Hvilket land", "grenser til", "Norge?", "Russland", "Island", "Danmark"};
String samfunnVanskelig5[] = {"Hvilket fylke", "ligger Oslo i?", "Rogaland", "Oslo", "Aust-agder"};

String matteLett1[] = {"Hva er", "5-1 ?","6", "4", "3"};
String matteLett2[] = {"Hvilket regne-", "stykke blir 3?", "5-3", "10-6", "7-4"};
String matteLett3[] = {"Hva er", "9-8 ?", "1", "7", "5"};
String matteLett4[] = {"Hva er", "3+6 ?", "9", "4", "8"};
String matteLett5[] = {"Hvilket regne-", "stykke blir 4", "7-5", "3-1", "6-2"};
String matteVanskelig1[] = {"Hva er halv-", "parten av 10kr?", "2kr + 2kr", "5kr + 5kr", "2kr + 3kr"};
String matteVanskelig2[] = {"Regn ut 3+4-5", "7", "2", "10"};
String matteVanskelig3[] = {"Hva er halv-", "parten av 8kr?", "9", "4", "6"};
String matteVanskelig4[] = {"Regn ut 1+3-3", "3", "0", "1"};
String matteVanskelig5[] = {"Regn ut 9-8+5", "6", "2", "8"};

String tekst = "";
int arrayIndeks = 0;
int delaySpm = 400;
int delayMeny = 250;

// LYS
/*int lysGronnSpiller = 12;
int lysRodSpiller = 17;
int lysGulSpiller = 18;
int lysBlaaSpiller = 19;*/

// MILLIS/DeBounce
int intervall = 5000;
long forrige = 0;
int intervallMeny = 400;
int dB = 0;

// RIKTIGE SVAR
int riktigeSvar[] = {0,0,0,0}; // grønn, rød, gul, blå
String spillere[] = {"Gronn", "Rod", "Gul", "Blaa"};
String a;
String b;
String c;
int hoyest = 0;
int indeks = 0;
int uavgjort = 0;
int uavgjortIndeks = 0;
int uavgjortTeller = 0;
int uavgjort2 = 0;
int uavgjortIndeks2 = 0;
int uavgjortTeller2 = 0;
int kaaringDelay = 1200;

// GRONN SPILLER
int gronnSvar = 51;
int svarAvgittGronn = false;

// ROD SPILLER
int rodSvar = 37;
boolean svarAvgittRod = false;

// GUL SPILLER
int gulSvar = 33;
boolean svarAvgittGul = false;

// BLAA SPILLER
int blaaSvar = 53;
boolean svarAvgittBlaa = false;

// MENY (setup)
String type[] = {"Gruppe Quiz"};
String fag[] = {"Matematikk", "Norsk", "Engelsk", "Samfunnsfag"};
String vanskelighetsGrad[] = {"Lett", "Vanskelig"};
int modusValg[] = {0, 3, 1}; // 0 teller som ett valg
int startQuizSetup[3];
int gulStor = 33;
int gronn = 12;
int rod = 13;
String string = "";
boolean notStarted = true;
int menyNr = 0;

// ÆØÅ
/*byte newChar0[8] = { B10000,B01000,B00100,B00010,B00001,B00010,B00100,B00000}; // >
byte Lae[8] ={ B00000,B00000,B11010,B00101,B01111,B10100,B11111,B00000}; // æ
byte Loe[8] ={ B00000,B00001,B01110,B10101,B10101,B01110,B10000,B00000}; // ø
byte Laa[8] ={ B00100,B00000,B01110,B00001,B01111,B10001,B01111,B00000}; // å
byte Sae[8] ={ B01111,B10100,B10100,B11110,B10100,B10100,B10111,B00000}; // Æ
byte Soe[8] ={ B00001,B01110,B10011,B10101,B11001,B01110,B10000,B00000}; // Ø
byte Saa[8] ={ B00100,B00000,B01110,B10001,B11111,B10001,B10001,B00000}; // Å*/

void setup() {
  // liquid i2c setup
  lcd.begin();
  // lcd setup
  lcd2.begin(16, 2);
  
  pinMode(gulStor, INPUT);
  pinMode(gronn, INPUT);
  pinMode(rod, INPUT);
  pinMode(gronnSvar, INPUT);
  pinMode(blaaSvar, INPUT);
  pinMode(gulSvar, INPUT);
  pinMode(rodSvar, INPUT);

  Serial.begin(9600);
  
  // oppsett for æøå bokstaver
  
  /*lcd.createChar(0, newChar0); // upload 8 selvdef. karakterer
  lcd.createChar(1, Lae); // æ
  lcd.createChar(2, Loe); // ø
  lcd.createChar(3, Laa); // å
  lcd.createChar(4, Sae); // Æ
  lcd.createChar(5, Soe); // Ø
  lcd.createChar(6, Saa); // Å*/
  lcd.clear();
}
void loop() {
  //startQuiz();
  //testSpm();
  meny();
  //testSpm();
  //testKnapp(gronn);
}
// MENY start
void meny() {
  if (notStarted == true) {
    notStarted = false;
    lcdPrintAlle(true,"Velkommen til",1,0);
    lcdPrintAlle(false,"Brettspillet!",1,1);
    delay(3000);
    lcdPrintAlle(true,"Velg oppsett",1,0);
    delay(2000);
    lcd.clear();
    lcd2.clear();
    velgType();
  }
}
// MENY-valg type
void velgType(){
  while (digitalRead(gulStor) != HIGH) {
    lcdPrintAlle(false,type[menyNr],0,0);
    if (menyNr != modusValg[0] && digitalRead(gronn) == HIGH) {
      menyNr++;
      deBounce();
      lcd.clear();
      lcd2.clear();
    }
    else if (menyNr != 0 && digitalRead(rod) == HIGH) {
      menyNr--;
      deBounce();
      lcd.clear();
      lcd2.clear();
    }
    else if (menyNr == modusValg[0] && digitalRead(gronn) == HIGH) {
      menyNr = 0;
      deBounce();
      lcd.clear();
      lcd2.clear();
    }
    else if (menyNr = 0 && digitalRead(rod) == HIGH) {
      menyNr = modusValg[0];
      deBounce();
      lcd.clear();
      lcd2.clear();
    }
    delay(50);
  }
  startQuizSetup[0] = menyNr;
  menyNr = 0;
  delay(300);
  lcd.clear();
  lcd2.clear();
  velgFag();
}
// MENY valg fag
void velgFag() {
  while (digitalRead(gulStor) != HIGH) {
    lcdPrintAlle(false,fag[menyNr],0,0);
    if (menyNr != modusValg[1] && digitalRead(gronn) == HIGH) {
      menyNr++;
      deBounce();
      lcd.clear();
      lcd2.clear();
    }
    else if (menyNr != 0 && digitalRead(rod) == HIGH) {
      menyNr--;
      deBounce();
      lcd.clear();
      lcd2.clear();
    }
    else if (menyNr == modusValg[1] && digitalRead(gronn) == HIGH) {
      menyNr = 0;
      deBounce();
      lcd.clear();
      lcd2.clear();
    }
    else if (menyNr == 0 && digitalRead(rod) == HIGH) {
      menyNr = modusValg[1];
      deBounce();
      lcd.clear();
      lcd2.clear();
    }
    delay(50);
  }
  startQuizSetup[1] = menyNr;
  menyNr = 0;
  delay(300);
  lcd.clear();
  lcd2.clear();
  velgGrad();
}

// MENY-valg vanskelighetsgrad
void velgGrad() {
  while (digitalRead(gulStor) != HIGH) {
    lcdPrintAlle(false,vanskelighetsGrad[menyNr],0,0);
    if (menyNr != modusValg[2] && digitalRead(gronn) == HIGH) {
      menyNr++;
      deBounce();
      lcd.clear();
      lcd2.clear();
    }
    else if (menyNr != 0 && digitalRead(rod) == HIGH) {
      menyNr--;
      deBounce();
      lcd.clear();
      lcd2.clear();
    }
    else if (menyNr == modusValg[2] && digitalRead(gronn) == HIGH) {
      menyNr = 0;
      deBounce();
      lcd.clear();
      lcd2.clear();
    }
    else if (menyNr == 0 && digitalRead(rod) == HIGH) {
      menyNr = modusValg[2];
      deBounce();
      lcd.clear();
      lcd2.clear();
    }
    delay(50);
  }
  startQuizSetup[2] = menyNr;
  menyNr = 0;
  delay(300);
  startQuiz(startQuizSetup);
}
// START quiz
void startQuiz(int modus[]) {
  // modus[] = {type, fag, vanskelighetsGrad} (fag = Matte, Norsk, Engelsk, Samfunnsfag) (vanskelighetsGrad = Lett, Vanskelig)
  // hvis lett er valgt
  if (modus[2] == 0) {
    if (modus[1] == 0) {
      // parametre: array, strenger i arrayen, indeks til riktig svar
      kjorSpm(matteLett1, 5, 3);
      kjorSpm(matteLett2, 5, 4);
      kjorSpm(matteLett3, 5, 2);
      kjorSpm(matteLett4, 5, 2);
      kjorSpm(matteLett5, 5, 4);
      sjekkVinner();
      kjorNy();
    }
    else if (modus[1] == 1) {
      kjorSpm(norskLett1, 5, 3);
      kjorSpm(norskLett2, 5, 2);
      kjorSpm(norskLett3, 5, 3);
      kjorSpm(norskLett4, 6, 5);
      kjorSpm(norskLett5, 6, 4);
      sjekkVinner();
      kjorNy();
    }
    else if (modus[1] == 2) {
      kjorSpm(engelskLett1, 5, 4);
      kjorSpm(engelskLett2, 5, 2);
      kjorSpm(engelskLett3, 5, 3);
      kjorSpm(engelskLett4, 5, 2);
      kjorSpm(engelskLett5, 5, 3);
      sjekkVinner();
      kjorNy();
    }
    else if (modus[1] == 3) {
      kjorSpm(samfunnLett1, 5, 3);
      kjorSpm(samfunnLett2, 5, 3);
      kjorSpm(samfunnLett3, 5, 3);
      kjorSpm(samfunnLett4, 5, 4);
      kjorSpm(samfunnLett5, 5, 4);
      sjekkVinner();
      kjorNy();
    }
  }
  // hvis vanskelig er valgt
  else if (modus[2] == 1) {
    if (modus[1] == 0) {
      kjorSpm(matteVanskelig1, 5, 4);
      kjorSpm(matteVanskelig2, 4, 2);
      kjorSpm(matteVanskelig3, 5, 3);
      kjorSpm(matteVanskelig4, 4, 3);
      kjorSpm(matteVanskelig5, 4, 1);
      sjekkVinner();
      kjorNy();
    }
    else if (modus[1] == 1) {
      kjorSpm(norskVanskelig1, 5, 3);
      kjorSpm(norskVanskelig2, 5, 2);
      kjorSpm(norskVanskelig3, 5, 4);
      kjorSpm(norskVanskelig4, 5, 2);
      kjorSpm(norskVanskelig5, 6, 4);
      sjekkVinner();
      kjorNy();
    }
    else if (modus[1] == 2) {
      kjorSpm(engelskVanskelig1, 5, 3);
      kjorSpm(engelskVanskelig2, 5, 3);
      kjorSpm(engelskVanskelig3, 6, 4);
      kjorSpm(engelskVanskelig4, 6, 5);
      kjorSpm(engelskVanskelig5, 5, 3);
      sjekkVinner();
      kjorNy();
    }
    else if (modus[1] == 3) {
      kjorSpm(samfunnVanskelig1, 5, 4);
      kjorSpm(samfunnVanskelig2, 5, 4);
      kjorSpm(samfunnVanskelig3, 5, 3);
      kjorSpm(samfunnVanskelig4, 6, 3);
      kjorSpm(samfunnVanskelig5, 5, 3);
      sjekkVinner();
      kjorNy();
    }
  }
}
void tilbakeStillSvar() {
  svarAvgittGronn = false;
  svarAvgittRod = false;
  svarAvgittBlaa = false;
  svarAvgittGul = false;
}
void tilbakeStillKaaring() {
  hoyest = 0;
  indeks = 0;
  uavgjort = 0;
  uavgjortIndeks = 0;
  uavgjortTeller = 0;
  uavgjort2 = 0;
  uavgjortIndeks2 = 0;
  uavgjortTeller2 = 0;
  riktigeSvar[0] = 0;
  riktigeSvar[1] = 0;
  riktigeSvar[2] = 0;
  riktigeSvar[3] = 0;
}
// KÅRING vinner
// riktigeSvar[] = {grønn, rød, gul, blå}
void sjekkVinner(){
  for (int i = 0; i < 4; i++) {
    if (riktigeSvar[i] > hoyest) {
      hoyest = riktigeSvar[i];
      indeks = i;
    }
    else if (riktigeSvar[i] != 0 && riktigeSvar[i] == hoyest && uavgjortTeller == 0) {
      uavgjort = riktigeSvar[i];
      uavgjortIndeks = i;
      uavgjortTeller++;
    }
    else if (riktigeSvar[i] != 0 && uavgjortTeller != 0 && riktigeSvar[i] == uavgjort && uavgjortTeller2 == 0) {
      uavgjort2 = riktigeSvar[i];
      uavgjortIndeks2 = i;
      uavgjortTeller2++;
    }
  }
  if (riktigeSvar[0] == riktigeSvar[1] && riktigeSvar[0] == riktigeSvar[2] && riktigeSvar[0] == riktigeSvar[3]) {
    lcdPrintAlle(true, "Uavgjort!", 0, 0);
    lcdPrintAlle(false, "mellom alle", 0, 1);
    delay(kaaringDelay);
    tilbakeStillKaaring();
  }
  else if (hoyest == uavgjort && hoyest == uavgjort2) {
    a = spillere[indeks];
    b = spillere[uavgjortIndeks];
    c = spillere[uavgjortIndeks2];
    lcdPrintAlle(true, "Uavgjort!", 0, 0);
    delay(kaaringDelay);
    lcdPrintAlle(true, a, 0, 0);
    lcdPrintAlle(false, b, 6, 0);
    lcdPrintAlle(false, "og", 0, 1);
    lcdPrintAlle(false, c, 6, 1);
    delay(kaaringDelay);
    tilbakeStillKaaring();
  }
  else if (hoyest == uavgjort) {
    a = spillere[indeks];
    b = spillere[uavgjortIndeks];
    lcdPrintAlle(true, "Uavgjort!", 0, 0);
    lcdPrintAlle(false, a, 0, 1);
    lcdPrintAlle(false, b, 6, 1);
    delay(kaaringDelay);
    tilbakeStillKaaring();
  }
  else {
    a = spillere[indeks];
    lcdPrintAlle(true, "Vinner er:", 0,0);
    lcdPrintAlle(false, a, 0,1);
    delay(kaaringDelay);
    tilbakeStillKaaring();
  }
}
/*void kjorRiktigSvarLys(){
  if(grontLysOk   = true){
   for (int x=0; x<10; x++){
      digitalWrite(lysGronnSpiller, HIGH);
      delay(125);
      digitalWrite(lysGronnSpiller, LOW);
      delay(125);
   }
  }
  else if(riktigSvarRod = true){
    for (int x=0; x<10; x++){
      digitalWrite(lysRodSpiller, HIGH);
      delay(125);
      digitalWrite(lysRodSpiller, LOW);
      delay(125);
   }
  }
  else if(riktigSvarGul = true){
    for (int x=0; x<10; x++){
      digitalWrite(lysGulSpiller, HIGH);
      delay(125);
      digitalWrite(lysGulSpiller, LOW);
      delay(125);
   }
  }
  else if(riktigSvarGronn = true){
    for (int x=0; x<10; x++){
      digitalWrite(lysGulSpiller, HIGH);
      delay(125);
      digitalWrite(lysGulSpiller, LOW);
      delay(125);
   }
  }
}*/


// printe til alle lcd skjermer
void lcdPrintAlle (boolean lcdClear, String tekst2, int lengde, int bredde) {
  if (lcdClear == true) {
    lcd.clear();
    lcd2.clear();
    lcd.setCursor(lengde,bredde);
    lcd2.setCursor(lengde,bredde);
    //lcd3.setCursor(0,0);  
    lcd.print(tekst2);
    lcd2.print(tekst2);
    //lcd3.print(tekst);
  }
  else {
    lcd.setCursor(lengde,bredde);
    lcd2.setCursor(lengde,bredde);
    //lcd3.setCursor(0,0);  
    lcd.print(tekst2);
    lcd2.print(tekst2);
    //lcd3.print(tekst);
  }
}
// test metode
/*void testKnapp(int knapp){
  if(digitalRead(knapp) == HIGH){
    Serial.print("Knapp er trykket");
    delay(200);
  }
}*/

// registrer svar
void regSvar(boolean riktig) {
  if (riktig == true) {
    while(millis() - forrige < intervall){
      if(svarAvgittGronn == false && digitalRead(gronnSvar) == HIGH){
        riktigeSvar[0] += 1;
        svarAvgittGronn = true;
      }
      if(svarAvgittRod == false && digitalRead(rodSvar) == HIGH){
        riktigeSvar[1] += 1;
        svarAvgittRod = true;
      }
      if(svarAvgittGul == false && digitalRead(gulSvar) == HIGH){
        riktigeSvar[2] += 1;
        svarAvgittGul = true;
      }
      if(svarAvgittBlaa == false && digitalRead(blaaSvar) == HIGH){
        riktigeSvar[3] += 1;
        svarAvgittBlaa = true;
      }
    }
  }
  else {
    while(millis() - forrige < intervall){
      if(svarAvgittGronn == false && digitalRead(gronnSvar) == HIGH){
        svarAvgittGronn = true;
      }
      if(svarAvgittRod == false && digitalRead(rodSvar) == HIGH){
        svarAvgittRod = true;
      }
      if(svarAvgittGul == false && digitalRead(gulSvar) == HIGH){
        svarAvgittGul = true;
      }
      if(svarAvgittBlaa == false && digitalRead(blaaSvar) == HIGH){
        svarAvgittBlaa = true;
      }
    }
  }
}
void kjorNy() {
  notStarted = true;
  delay(2000);
}
// deBounce for meny styring
void deBounce() {
  dB = millis();
  while (millis() - dB < intervallMeny) {
  }
}

/*------------------------------------------------------------------------------

   Metode for aa bestemme hvilket sett med spørsmål som skal stilles med følgende parametre:
   
   array[] - hvilket spørsmålsett skal stilles
   antStrings - hvor mange strenger spørsmålsettet består av (ikke medregnet 0)
   indeksRiktigSvar - hvilken indeksplass regSvar skal være true
   
------------------------------------------------------------------------------*/
   
void kjorSpm(String array[], int antStrings, int indeksRiktigSvar){
  arrayIndeks = 0;
  if (antStrings == 4) {
    if (indeksRiktigSvar == 1) {
      lcdPrintAlle(true,array[arrayIndeks],0,0);
      delay(delaySpm + 3000);
      arrayIndeks++;
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(true);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(false);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks = 0;
      forrige = millis();
      regSvar(false);
      forrige = millis();
    }
    else if (indeksRiktigSvar == 2) {
      lcdPrintAlle(true,array[arrayIndeks],0,0);
      delay(delaySpm + 3000);
      arrayIndeks++;
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(false);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(true);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks = 0;
      forrige = millis();
      regSvar(false);
      forrige = millis();
    }
    else if (indeksRiktigSvar == 3) {
      lcdPrintAlle(true,array[arrayIndeks],0,0);
      delay(delaySpm + 3000);
      arrayIndeks++;
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(false);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(false);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks = 0;
      forrige = millis();
      regSvar(true);
      forrige = millis();
    }
  }
  else if (antStrings == 5) {
    if (indeksRiktigSvar == 2) {
      lcdPrintAlle(true,array[arrayIndeks],0,0);
      delay(delaySpm);
      arrayIndeks++;
      lcdPrintAlle(false,array[arrayIndeks],0,1);
      delay(delaySpm + 3000);
      arrayIndeks++;
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(true);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(false);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks = 0;
      forrige = millis();
      regSvar(false);
      forrige = millis();
    }
    else if (indeksRiktigSvar == 3) {
      lcdPrintAlle(true,array[arrayIndeks],0,0);
      delay(delaySpm);
      arrayIndeks++;
      lcdPrintAlle(false,array[arrayIndeks],0,1);
      delay(delaySpm + 3000);
      arrayIndeks++;
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(false);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(true);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks = 0;
      forrige = millis();
      regSvar(false);
      forrige = millis();
    }
    else if (indeksRiktigSvar == 4) {
      lcdPrintAlle(true,array[arrayIndeks],0,0);
      delay(delaySpm);
      arrayIndeks++;
      lcdPrintAlle(false,array[arrayIndeks],0,1);
      delay(delaySpm + 3000);
      arrayIndeks++;
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(false);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(false);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks = 0;
      forrige = millis();
      regSvar(true);
      forrige = millis();
    }
  }
  else if (antStrings == 6) {
    if (indeksRiktigSvar == 3) {
      lcdPrintAlle(true,array[arrayIndeks],0,0);
      delay(delaySpm);
      arrayIndeks++;
      lcdPrintAlle(false,array[arrayIndeks],0,1);
      delay(delaySpm + 1600);
      arrayIndeks++;
      lcdPrintAlle(true,array[arrayIndeks],0,0);
      delay(delaySpm + 2000);
      arrayIndeks++;
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(true);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(false);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      regSvar(false);
      arrayIndeks = 0;
      forrige = millis();
    }
    else if (indeksRiktigSvar == 4) {
      lcdPrintAlle(true,array[arrayIndeks],0,0);
      delay(delaySpm);
      arrayIndeks++;
      lcdPrintAlle(false,array[arrayIndeks],0,1);
      delay(delaySpm + 3000);
      arrayIndeks++;
      lcdPrintAlle(true,array[arrayIndeks],0,0);
      delay(delaySpm + 2000);
      arrayIndeks++;
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(false);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(true);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      regSvar(false);
      arrayIndeks = 0;
      forrige = millis();
    }
    else if (indeksRiktigSvar == 5) {
      lcdPrintAlle(true,array[arrayIndeks],0,0);
      delay(delaySpm);
      arrayIndeks++;
      lcdPrintAlle(false,array[arrayIndeks],0,1);
      delay(delaySpm + 3000);
      arrayIndeks++;
      lcdPrintAlle(true,array[arrayIndeks],0,0);
      delay(delaySpm + 2000);
      arrayIndeks++;
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(false);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      arrayIndeks++;
      forrige = millis();
      regSvar(false);
      lcdPrintAlle(true,array[arrayIndeks],0,1);
      delay(delaySpm);
      regSvar(true);
      arrayIndeks = 0;
      forrige = millis();
    }
  }
  tilbakeStillSvar();
  lcdPrintAlle(true, "Riktig svar er:",0,0);
  delay(delaySpm);
  lcdPrintAlle(false, array[indeksRiktigSvar],0,1);
  delay(delaySpm + 2000);
}
