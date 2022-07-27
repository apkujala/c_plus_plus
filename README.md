## Eikuvvaa!

Kantsii ehkä kattoa monta "prossua" koneessa on niin pistää sen määrän rng:ksi ni saa jotain eroa koska tuo async osasto on mun mielestä vähä väärin siinä.
Todennäköisesti se get() osio olis pitäny ratkasta jotenki toisella tavalla mutta nyt ei jaksa. Ongelmaksi tuli siis enemmänki se että olis pitäny tehdä ensin tää kurssi ja sitten tuo concurrent uusiks että olis muistanu molemmista kaiken tarvittavan...

Eli työn luonteen kannalta varsinainen käyttö on nolla.
Ohjelma kysyy kuinka monta satunnaislukugeneraattoria tehdään.
Generaattori arpoo 10m-100m satunnaislukua ja tais printata seen viimeisen.
Toki tommosessa tehtävässä tuo rand() toimii hölmösti koska se pitäs heittää jokaiselle oliolle oma srand()
Yleensä sitä ei suositella mutta concurrent kurssin alussa tuli selväksi että randomi on tuossa oma perehtymisen kohde.

Hölmö tehtävähän tuo lopputyöksi on mutta tosiaan halusin oppia perusteet jotta saan tuon tehtyä.


Nuo tekstifilekset on ihan vaan jotta voi sanoa että kyllä sitäkin siinä tehtiin.
No aika väkisin pitää tommoseen tehtävään pistää käyttöliittymää tai tiedostoa. No olishan sitä tietty voinu printtaa tiedostoon ne kaikki satunnaisluvut..

### AI NIIN!!!

tehtävähän oli tämän näköinen:

1. Create a new console app.

2. Declare a class 'RandomNumberGenerator'. In class, specify *enum* of task type as *LIGHT* or *HEAVY*.

    - If RandomNumberGenerator is *LIGHT*, it will generate 100 random numbers.
    
    - If RandomNumberGenerator is *HEAVY*, it will generate 10 000 000 random numbers.
    
3. Allocate 100 RandomNumberGenerators and set the task type to *LIGHT* or *HEAVY* randomly.

4. Run the allocated RandomNumberGenerators as async tasks.

    - If generator is *LIGHT*, use deferred launching.
    
    - If generator is *HEAVY*, use async launching.
    
5. Measure how long it takes to complete all generators.

6. Modify your code to run all tasks with async launching.

7. Measure how long it takes to complete all generators.

8. Add comments into the source code of your findings. Which way is faster? Why?
