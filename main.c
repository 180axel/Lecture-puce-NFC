#include <Wire.h>
#include <Adafruit_NFCShield_I2C.h>
#include <SoftwareSerial.h>

#define IRQ (2) // DEFINITION DE L'INTERRUPTION
#define RESET (3) // NON CONNECTE PAR DEFAUT SUR LE SHIELD NFC

Adafruit_NFCShield_I2C nfc(IRQ, RESET);

void setup(void) {
    Serial.begin(115200);
    Serial.println("Hello !");

    nfc.begin();
    uint32_t versiondata = nfc.getFirmwareVersion();

    if (! versiondata) {
        Serial.print("Didn't find PN53x board");
        while (1); // halt
    }

    // Got ok data, print it out!
    Serial.print("Found chip PN5");
    Serial.println((versiondata>>24) & 0xFF, HEX);
    Serial.print("Firmware ver. ");
    Serial.print((versiondata>>16) & 0xFF, DEC);
    Serial.print('.');
    Serial.println((versiondata>>8) & 0xFF, DEC);
    // Set the max number of retry attempts to read from a card
    // This prevents us from waiting forever for a card, which is
    // the default behaviour of the PN532.  nfc.setPassiveActivationRetries(0xFF);
    // configure board to read RFID tags nfc.SAMConfig();

    Serial.println("Waiting for an ISO14443A card"); }

void loop(void) {
    boolean success;
    uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
    uint8_t uidLength;

    // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
    // 'uid' will be populated with the UID, and uidLength will indicate
    // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)

    success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);

    if (success) {
        Serial.println("Found a card!");
        Serial.print("UID Length: ");
        Serial.print(uidLength, DEC);
        Serial.println(" bytes");
        Serial.print("UID Value: ");
        for (uint8_t i = 0; i < uidLength; i++) {
            Serial.print(" 0x");
            Serial.print(uid[i], HEX);
        }

        Serial.println("");
        delay(1000);  // Wait 1 second before continuing
    }
    else
        Serial.println("Timed out waiting for a card"); // PN532 probably timed out waiting for a card

}
