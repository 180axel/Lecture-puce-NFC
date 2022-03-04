# Applications NFC (Near Field Communication - Communication proche sans contact).

>    - Ce shield AdaFruit utilise le **contrôleur PN532** et peut presque tout faire, lire comme écrire; des cartes ou des tags, communiquer avec des téléphones mais aussi agir comme un tag NFC.
>
>    - Parce qu'il est capable de lire et d'écrire des TAGs, vous pouvez toujours utiliser ce shield pour des projets orientés RFID.
>
>    - Il est également capable de traiter des tout autres types de tag NFC/RFID du Type 1 au 4.
>
>    - Le shield Adafruit a été conçu pour fonctionner sur une distance de 10 cm maximum en utilisant une technologie 13.56MHz.

## Utilisation

>    - ***Ecrivez*** et enregistrez votre code dans un fichier ***'.c'***

>    - ***Branchez*** votre arduino à votre ordinateur

>    - ***Chargez*** le code dans votre arduino

## usage

Par défaut le shield est configuré en **I2C**, et utilise donc moins de broches :
analogique 4 et 5 sont utilisées pour la communication I2C
La broche/pin digitale 2 est utilisée pour les notifications via **"interruption"**.
Cela signifie que votre programme ne doit pas constamment interroger
la carte RFID pour demander si un Tag est présent.

*La pin digitale 2 sera mise à la masse (pulled down) quand une carte,
téléphone, etc passe dans le champs de communication.
Vous pouvez changer la broche utilisée pour cette notification
si vous désirez garder la Pin 2 pour une autre chose.*
