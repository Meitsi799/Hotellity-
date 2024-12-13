// Eetu Tissari
// Hotellityö, 2p

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Luodaan aliohjelma, joka arpoo lukuja annetulta väliltä
// Voidaan käyttää huoneiden määrän ja huoneen hinnan arpomiseen
int satunnaisLuku(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Luodaan aliohjelma, joka näyttää varatut huoneet
void naytaVaratutHuoneet(const vector<bool>& varatutHuoneet, int huoneidenMäärä) {
   cout << "Varatut huoneet: ";
    for (int i = 0; i < huoneidenMäärä; i++) {
        if (varatutHuoneet[i]) {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
}

// Luodaan pääohjelma, joka varaa halutun huoneen käyttäjälle ja laskee varauksen hinnan
int main() {

    // Alustetaan satunnaislukugeneraattori
    srand(time(0));

    // Arvotaan huoneiden lukumäärä ja hinta per yö
    int huoneidenMäärä = satunnaisLuku(30, 70);
    int huoneenHinta = satunnaisLuku(80, 100);

    // Luodaan vektori, johon tallennetaan varatut huoneet
    vector<bool> varatutHuoneet(huoneidenMäärä, false); // true = huone varattu, false = huone vapaa
    char jatka; // Tätä muuttujaa voidaan käyttää kysyttäessä käyttäjältä, haluaako hän jatkaa
    
    // Ilmoitetaan käyttäjälle, kuinka monta huonetta hotellissa on ja paljonko yö maksaa
    cout << "Huoneita on " << huoneidenMäärä << ". Yhden yon hinta on " << huoneenHinta << " euroa." << endl;

    // Luodaan silmukka huoneiden varaamista varten
    do {
        int huoneenNumero;
        int öidenMäärä;

        // Kysytään käyttäjältä haluttu huonenumero
        while (true) {
            cout << "Anna varattava huonenumero (1-" << huoneidenMäärä << "): ";
            cin >> huoneenNumero;

            // Tarkistetaan, onko annettu numero sallitulla välillä
            if (huoneenNumero < 1 || huoneenNumero > huoneidenMäärä) {
                cout << "Virheellinen huonenumero. Yrita uudelleen." << endl;
                continue;
            }

            // Tarkistetaan, onko huone varattu
            if (varatutHuoneet[huoneenNumero - 1]) {
                cout << "Huone " << huoneenNumero << " on jo varattu. Valitse toinen huone." << endl;
                continue;
            }

            // Silmukkaa toistetaan, kunnes varattava huone on vapaa
            break;
        }

        // Käyttäjältä kysytään öiden määrää
        cout << "Montako yota varataan?: ";
        cin >> öidenMäärä;

        // Lasketaan ja näytetään loppusumma
        int loppusumma = öidenMäärä * huoneenHinta;
        cout << "Loppusumma on: " << loppusumma << " euroa" << endl;

        // Merkitään huone varatuksi
        varatutHuoneet[huoneenNumero - 1] = true;

        // Naytetään varatut huoneet
        naytaVaratutHuoneet(varatutHuoneet, huoneidenMäärä);

        // Kysytään käyttäjältä, haluaako tämä jatkaa
        cout << "Haluatko varata toisen huoneen? (k = kylla, e = ei): ";
        cin >> jatka;

        // Toistetaan silmukka, jos käyttäjä valitsee jatkaa
    } while (jatka == 'k');

    cout << "Kiitos, kun kaytit varausohjelmaa!";

    return 0;
}
