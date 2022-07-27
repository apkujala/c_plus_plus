
#include <iostream>
#include <fstream>
#include <future>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;
using namespace std::chrono;

// T‰ss‰ sit‰ nyt sitte aletaan kommentoimaan t‰t‰.

// Jo t‰‰ kohta oli v‰h‰ vaikee. Tulee tehtyy just v‰‰rin et alkaa tekee eik‰ tied‰ mit‰ tekee (eik‰ osaa).
// Heti kun malttoi alkaa mietti‰ ett‰ mit‰ m‰ haluan ett‰ t‰‰ ohjelma tekee ja mit‰ sen pit‰‰ sillon tehd‰.
// Mik‰ on enum? Pit‰‰kˆ sen olla tuolla classin sis‰ll‰ kun teht‰v‰ss‰ piti m‰‰ritt‰‰ enum. 
// Kun tajusin mietti‰ et mik‰ se enum niinku on niin yks solmu aukes. Siirsin sen t‰nne.
enum class Task_weight {
    LIGHT,
    HEAVY
};

class RandomNumberGenerator {
public:
 

    // T‰‰ class homma oli mulle aika kauhee peikko.
    // Tiesin asiat ja olin moneen kertaan n‰hny mutta koskaan ei tarvinu n‰in syv‰llisesti mietti‰ ilman mallia.
    // Ja se syntaksi!
    // Eih‰n tuo viel‰k‰‰n mik‰‰n monimutkanen ole mutta tossa nyt sitte p‰‰s v‰h‰ leikkii ja kokeilee et miten toimii.
    // Alkuper‰nen idea mulla oli ihan t‰ysin v‰‰r‰. En osanu siis heitt‰‰ tota vectoria tai listaa tonne classiin..
    // No miteh‰ se olis edes tarvinu niin menn‰.
    RandomNumberGenerator() {
        //Task_weight task_weight;
        // 
        // 
        // Eli t‰ss‰ nyt sitte arvotaan se enum LIGHT tai HEAVY
        int switch_weight = rand() % 2;
        cout << switch_weight << endl;
        if (switch_weight == 0){
            //task_weight = Task_weight::LIGHT;
            //cout << "LIGHT" << endl;
            x = Task_weight::LIGHT;
        }
        else {
            // T‰‰ alempi oli just sekoilua et miten tuo enum oikeintuolta saadaan ulos ja sis‰‰n, miks ei toimi.
            //Task_weight task_weight = Task_weight::HEAVY;
            //cout << "HEAVY" << endl;
            x = Task_weight::HEAVY;
        }
        // T‰‰ oli testi‰ varten ett‰ miten t‰‰ nyt oikein.
        /*
        if (x == Task_weight::LIGHT) {
            cout << "prkl" << endl;

        }
        */
    }

    // T‰‰ alunperin oli sit‰ varten ett‰ sais testattua mit‰ tuo nyt sitte tuolta palauttaa
    // Toki ihanaa yritt‰‰ saada enum ulos cout:illa...
    // No jonku testin sit‰ sitte osas rakentaa, ja tuo check2 on se
    Task_weight Check_weight() {
        return x;
    }
    
    string Check_weight2() {
        cout << "TESTING" << endl;
        if (x == Task_weight::LIGHT) {
            return "Light CHECK2";
        }
        else return "HEAVY CHECK2";
    }
    // Sopiikin hyvin ett‰ tuo vanha funktionimi on tuossa viel‰...
    int do_string() {
        if (Check_weight()==Task_weight::LIGHT) {
            cout << "Created_DEBUG_LIGHT" << endl;
            // Alkuper‰sess‰ piti olla 100/10000000 mutta tajusin ett‰ kun on 12 prossua ja ottaa 100 RNG:t‰ niin se jakautuu melko tasan
            // eli eroja tuli yll‰tt‰v‰n v‰h‰n. Kokeilin 12 threadilla niin alko tulla just sit‰ eroa.
            // Toiseksi sitte tajusin ett‰ se ett‰ tuo toimii ei kuulu taas TƒHƒN kurssiin vaan ett‰ t‰‰ toimii.
            // Ja nyt se toimii!
            for (int i = 0; i < 10000000; i++) {

                value = rand();
            }
        }
        else if (Check_weight() == Task_weight::HEAVY) {
            cout << "Created_DEBUG_HEAVY" << endl;
            //this->Check_weight();
            for (int i = 0; i < 100000000; i++) {

                value = rand();
            }
        }
        else {
            // T‰‰ oli testi sit‰ varten kun jossain kohtaa tuli 11001 alku ja silti printiss‰ oli tuo DEBUG_HEAVY jonku 10 kertaa
            // Enp‰ en‰‰ muista mik‰ sen korjas mutta j‰tet‰‰n muistoksi.
            cout << "MITVIT" << endl;
        }
            //return "keke";

        
        return value;
    }

private:
    // Miksi n‰in, no kai se pit‰‰ jotain suojausta opetella, ja vahva alku on t‰ss‰!
    int value = 0;
    Task_weight x;
    
};


int main()
{
    // Se ett‰ n‰‰ nyt asetellaan nollaksi ni en vaan jaksanu tota valitusta ett‰ pit‰s asettaa...
    int light_counter = 0;
    int heavy_counter = 0;
    int print_counter = 0;
    int print_counter2 = 0;
    //srand(time(0));
    int num_of_generators = 0;

    // Eli sitte leikit‰‰n filell‰. in-file-streamiin nasautetaan tuo file jonka tein et jos jaksais lukee tiedostosta
    // niiden RNG:n m‰‰r‰ mut into loppu kun se olis kuitenki ollu vaan tommosta pyˆrittely‰.
    string line;
    int numero = 0;
    ifstream myfile("berbe.txt");
    if (myfile.is_open())
    {
        // Aluks tosiaan oli tarkotus ett‰ lukee tuon lopussa tehdyn tiedoston ja kommentoi sit‰ mut..
        // otetaan siis yksi rivi
        getline(myfile, line);
        //t‰‰ki piti ettii et mites se saadaan intiksi kun pythonissa muka tosi eri tavalla..
        numero = stoi(line);
        //while (getline(myfile, line))
        //{
            // jaa, kahteen kertaan samaa kommenttia... 
            // Mit‰h‰ t‰h‰n olis tehny... 
            // voishan sit‰ kattoa et saisko tuon generaattoreiden m‰‰r‰n luettua tiedostosta jos se on olemassa
        //    cout << line << '\n';
        //}
        cout << "High chance this has been done before! " << endl;
        cout << "Berbe.txt filess‰ on numero" << numero << endl;
        myfile.close();
    }
    else cout << "Unable to open file";

    cout << "How many generators?\n";
    cin >> num_of_generators;
    

    // Elikk‰s, alustetaan pari vectoria, jo concurrent aikana oli ongelma jo t‰ss‰ kun en tajunut ett‰ mites muka array noista tehd‰‰n
    // tai yleens‰k‰ et mites array oikein... siit‰ j‰i sit tuo vector ajattelu...
    vector<RandomNumberGenerator*> randi;

    // eli tarvitaan siis asynciin t‰mmˆnen systeemi
    // eli tuo tuleva async palauttaa futureen tallennetun tiedon ja t‰ss‰ alustetaan lista niit‰
    // toim.huom. tuo xxx<yyy> on ollu kyll‰ v‰h‰ hepreaa mut nyth‰n se alkaa hahmottua sekin
    vector<future<int>> result;

    for (int i = 0; i < num_of_generators; i++)
    {
        // eli joo tehd‰‰n oliot, t‰t‰ kirjottaessa tajuan tˆrm‰nneeni samaan ongelmaan muuallakin
        // eli jos tehd‰‰n n‰in noita olioita, niin miten lˆyt‰‰ jonkun niiden joukosta jonkun tietyn kun niille ei anna nimi‰
        // no ehk‰ se selvi‰‰ ensi numerossa
        randi.push_back(new RandomNumberGenerator());
    }
    //Testiksi tamakin
    //cout << randi[0]->Check_weight2()<< endl;
    // joo eli piti aikaa ottaa, sekin oli yll‰tt‰v‰n berberi‰ kun koko koodi toimii v‰lill‰ niin omituisesti
    auto start = system_clock::now();

    for (int i = 0; i < num_of_generators; i++) {
        // eli t‰ss‰ piti tsekata ett‰ onko se LIGHT vai HEAVY ja sen mukaan tehd‰ tuo async/deferred launchi
        if (randi[i]->Check_weight() == Task_weight::LIGHT) {

            // result vectoriin siis nasautetaan sis‰‰n n‰it‰ asyncin‰ suoritettavia funktioita
            // tuossaki oli pointereiden kanssa v‰h‰n ihmetyst‰
            result.push_back(async(launch::deferred, &RandomNumberGenerator::do_string, randi[i]));
            //future<int>keke = (async(launch::deferred, &RandomNumberGenerator::do_string, randi[i]));
            cout << "Lihti" << endl;
            // T‰‰ ei toimi koska se odottaa tuloksen ja vasta sitten siirtyy seuraavaan
            //int kejo = result[i].get();
            //cout << kejo << endl;
            light_counter++;
        }
        else {
            result.push_back(async(launch::async, &RandomNumberGenerator::do_string, randi[i]));
            //future<int>keke = async(launch::async, &RandomNumberGenerator::do_string, randi[i]);
            cout << "hevi" << endl;
            //int kejo = result[i].get();
            //cout << kejo << endl;
            heavy_counter++;
        }
    }
    
    for (int i = 0; i < num_of_generators; i++) {
        // t‰ss‰ sitten haetaan tuolla getill‰ tuon async synsteemin arvo, t‰‰ ei ehk‰ ihan worki niin kun haluisin
        // tai ainakin siin‰ on v‰h‰ omituista (ja vaikeeta selvitt‰‰) toimintaa
        // tuo selvityksen vaikeus tuli tuolla kurssilla monesti esiin, eli todella vaikea debugata kun 12 threadia tekee eri aikaan
        // mutta concurrentissa yleens‰ suurin ongelma toki on se ett‰ jos halutaan vaihtaa yht‰ ja samaa arvoa

        int kejo = result[i].get();
        //cout << result.get();
        cout << kejo << endl;
        // ihan vaan debuggausta varten
        print_counter++;
    }
    
    auto end = system_clock::now();
    
    //randi.push_back(new RandomNumberGenerator());
    // Aika sama tavara mutta kaikki on asyncin‰
    // jossain vaiheessa tuli jotain muistierroria joka nyt j‰lkeenp‰in ajateltuna voi olla hyv‰ asia
    // eli se voi johtua siit‰ ett‰ t‰‰ uus veto alko muuttaa noita ekan version vectoreita kun se oli viel‰ pyˆrim‰ss‰
    // eli siksi tein sitte uudet vectorit t‰h‰n, ja nyt kun sitte homma on toimimassa niin kokeilinjosko toimii ilman
    // ja parin testin j‰lkeen ainaki toimii
    vector<RandomNumberGenerator*> randi2;
    vector<future<int>> result2;

    for (int i = 0; i < num_of_generators; i++)
    {
        randi2.push_back(new RandomNumberGenerator());
    }

    auto start2 = system_clock::now();

    for (int i = 0; i < num_of_generators; i++) {
        result2.push_back(async(launch::async, &RandomNumberGenerator::do_string, randi[i]));
        //future<int>keke2 = async(launch::async, &RandomNumberGenerator::do_string, randi[i]);
        //int kejo2 = result2[i].get();
        //cout << "Num2_" << kejo2 << endl;
    }
    //int perperi = result2.get();
    //cout << randi.result.get();
    
    for (int i = 0; i < num_of_generators; i++) {
        int kejo2 = result2[i].get();
        //cout << result.get();
        cout << "Number2" << kejo2 << endl;
        print_counter2++;
    }
    
    std::cout << "Hello World!\n";
    // Eli kyll‰ t‰ss‰ taas pikkuhiljaa oppi lis‰‰ n‰it‰ perusasioita joka oli tietty kurssin tarkoitus
    // Ei t‰‰ nyt mik‰‰n black jack ole mutta p‰‰sin tavoitteeseeni.
    // Voishan n‰‰ tietty olla myˆs omissa tiedostoissa mut antaa olla, simppeli homma se...
    // Kiitos.
    auto end2 = system_clock::now();
    cout << "Total time (defer/async) = " << duration_cast<seconds>(end - start).count() << " Seconds\n";
    cout << "**********" << endl;
    cout << "Total time (all async) = " << duration_cast<seconds>(end2 - start2).count() << " Seconds\n";
    cout << "Lights" << light_counter << endl;
    cout << "HEAVYs" << heavy_counter <<endl;
    cout << "******" << endl;
    cout << "Count_1: " << print_counter << " Count_2: " << print_counter2 << endl;
    ofstream test_file;
    test_file.open("testi_kuhan_vaan.txt");
    test_file << "Counter countered " << heavy_counter << " HEAVY printereds last time perkele.\n";
    test_file << "Counter countered " << light_counter << " light printereds.";
    test_file.close();
    return 0;
}
