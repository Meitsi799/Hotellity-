// Eetu Tissari
// Hotellity�, 2p

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Luodaan aliohjelma, joka arpoo lukuja annetulta v�lilt�
// Voidaan k�ytt�� huoneiden m��r�n ja huoneen hinnan arpomiseen
int satunnaisLuku(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Luodaan aliohjelma, joka n�ytt�� varatut huoneet
void naytaVaratutHuoneet(const vector<bool>& varatutHuoneet, int huoneidenM��r�) {
   cout << "Varatut huoneet: ";
    for (int i = 0; i < huoneidenM��r�; i++) {
        if (varatutHuoneet[i]) {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
}

// Luodaan p��ohjelma, joka varaa halutun huoneen k�ytt�j�lle ja laskee varauksen hinnan
int main() {

    // Alustetaan satunnaislukugeneraattori
    srand(time(0));

    // Arvotaan huoneiden lukum��r� ja hinta per y�
    int huoneidenM��r� = satunnaisLuku(30, 70);
    int huoneenHinta = satunnaisLuku(80, 100);

    // Luodaan vektori, johon tallennetaan varatut huoneet
    vector<bool> varatutHuoneet(huoneidenM��r�, false); // true = huone varattu, false = huone vapaa
    char jatka; // T�t� muuttujaa voidaan k�ytt�� kysytt�ess� k�ytt�j�lt�, haluaako h�n jatkaa
    
    // Ilmoitetaan k�ytt�j�lle, kuinka monta huonetta hotellissa on ja paljonko y� maksaa
    cout << "Huoneita on " << huoneidenM��r� << ". Yhden yon hinta on " << huoneenHinta << " euroa." << endl;

    // Luodaan silmukka huoneiden varaamista varten
    do {
        int huoneenNumero;
        int �idenM��r�;

        // Kysyt��n k�ytt�j�lt� haluttu huonenumero
        while (true) {
            cout << "Anna varattava huonenumero (1-" << huoneidenM��r� << "): ";
            cin >> huoneenNumero;

            // Tarkistetaan, onko annettu numero sallitulla v�lill�
            if (huoneenNumero < 1 || huoneenNumero > huoneidenM��r�) {
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

        // K�ytt�j�lt� kysyt��n �iden m��r��
        cout << "Montako yota varataan?: ";
        cin >> �idenM��r�;

        // Lasketaan ja n�ytet��n loppusumma
        int loppusumma = �idenM��r� * huoneenHinta;
        cout << "Loppusumma on: " << loppusumma << " euroa" << endl;

        // Merkit��n huone varatuksi
        varatutHuoneet[huoneenNumero - 1] = true;

        // Naytet��n varatut huoneet
        naytaVaratutHuoneet(varatutHuoneet, huoneidenM��r�);

        // Kysyt��n k�ytt�j�lt�, haluaako t�m� jatkaa
        cout << "Haluatko varata toisen huoneen? (k = kylla, e = ei): ";
        cin >> jatka;

        // Toistetaan silmukka, jos k�ytt�j� valitsee jatkaa
    } while (jatka == 'k');

    cout << "Kiitos, kun kaytit varausohjelmaa!";

    return 0;
}
