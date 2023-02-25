#include <stdio.h>

#define NUM_STUDENTË 5
#define NOTA_KALIMIT 5

// struct për të ruajtur informatat e studentit
struct student {
    int id;
    int pikë;
    int nota;
};

// funksion për të llogaritur notën bazuar në pikët e studentit
int llogaritNotën(int pikë) {
    if (pikë >= 90) {
        return 10;
    } else if (pikë >= 80) {
        return 9;
    } else if (pikë >= 70) {
        return 8;
    } else if (pikë >= 60) {
        return 7;
    } else if (pikë >= 50) {
        return 6;
    } else {
        return 5;
    }
}

int main() {
    struct student studentët[NUM_STUDENTË];
    int i, studentëtQëKalojnë = 0, totaliIPikëve = 0;
    float notaMesatare = 0;
    int rezultatiMaksimal = 0;

    // hyrja e informatave të studentit
    for (i = 0; i < NUM_STUDENTË; i++) {
        printf("Vendosni ID-në dhe pikët për studentin %d: ", i+1);
        scanf("%d %d", &studentët[i].id, &studentët[i].pikë);

        // kontrolloni për pikë të pavlefshme
        if (studentët[i].pikë < 0 || studentët[i].pikë > 100) {
            printf("Pikët e pavlefshme për studentin %d. Dil nga programi.\n", studentët[i].id);
            return 0;
        }

        // llogaritja e notës
        studentët[i].nota = llogaritNotën(studentët[i].pikë);

        // kontrolloni nëse studenti ka kaluar provimin
        if (studentët[i].nota > NOTA_KALIMIT) {
            studentëtQëKalojnë++;
            totaliIPikëve += studentët[i].pikë;
            notaMesatare += studentët[i].nota;
        }

        // kontrolloni për rezultatin maksimal
        if (studentët[i].pikë > rezultatiMaksimal) {
            rezultatiMaksimal = studentët[i].pikë;
        }
    }
    // llogaritja e notës mesatare për studentët që kaluan
    notaMesatare /= studentëtQëKalojnë;

    printf("\nStudentët që e kaluan provimin:\n");
    for (i = 0; i < NUM_STUDENTË; i++) {
        if (studentët[i].nota > NOTA_KALIMIT) {
            printf("ID: %d, Nota: %d\n", studentët[i].id, studentët[i].nota);
        }
    }

    printf("\nStudentët që nuk e kaluan provimin:\n");
    for (i = 0; i < NUM_STUDENTË; i++) {
        if (studentët[i].nota <= NOTA_KALIMIT) {
            printf("ID: %d, Nota: %d\n", studentët[i].id, studentët[i].nota);
        }
    }

    printf("\nTotali i studentëve që kaluan: %d\n", studentëtQëKalojnë);
    if(studentëtQëKalojnë>0)
        printf("Nota mesatare për studentët që kaluan: %.2f\n", notaMesatare);
    else
        printf("Asnjë student nuk e ka kaluar provimin\n");
    printf("Rezultati maksimal: %d\n", rezultatiMaksimal);

    return 0;
}


// Kodi fillon duke përfshirë dhe duke definuar dy konstante, NUM_STUDENTË dhe NOTA_KALIMIT. NUM_STUDENTË është vendosur në 5, dhe kjo përdoret më vonë për të përcaktuar madhësinë e array-it të studentëve. NOTA_KALIMIT është vendosur në 5 dhe kjo përdoret më vonë për të përcaktuar notën minimale që një student duhet të ketë për të kaluar provimin.
// Më pas, kodi përcakton një struct për të ruajtur informatat e studentit. Struktura përmban fushat id, pikë dhe nota.
// Kodi pastaj përfshin një funksion llogaritNotën() që llogarit notën e studentit bazuar në pikët e tij. Funksioni llogaritNotën() marrë një parametër pikë dhe kthehet një int që përfaqëson notën e studentit.
// Në funksionin main(), kodi krijon një array të studentëve dhe deklaron disa variabla që do të përdoren më vonë në kod.
// Më pas, kodi në një cikël for, i cili përdoret për të hyrë informatat e studentit. Për secilin student, kodi kërkon që përdoruesi të vendosë ID-në dhe pikët e studentit, dhe pastaj kontrollon nëse pikët janë të vlefshme (duhet të jenë ndërmjet 0 dhe 100).
// Nëse pikët janë të vlefshme, kodi llogarit notën e studentit duke thirrur funksionin llogaritNotën(). Më pas, kodi kontrollon nëse studenti ka kaluar provimin duke kontrolluar nëse nota e studentit është më e madhe se NOTA_KALIMIT.
// Nëse studenti ka kaluar provimin, kodi ndryshon numrin e studentëve që kaluan dhe variablat e tjera që do të përdoren më vonë në kod, siç është totali i pikëve të studentëve që kaluan dhe nota mesatare e studentëve që kaluan. Kodi gjithashtu kontrollon nëse pikët e studentit janë më të larta se rezultati maksimal i të gjitha pikëve deri tani.
// Pas ciklit for, kodi llogarit notën mesatare të studentëve që kaluan duke ndarë totalin e pikëve me numrin e studentëve që kaluan.
// Më pas, kodi shfaq studentët që kaluan provimin dhe studentët që nuk e kaluan provimin duke përdorur cikle for dhe kontrollin e notës së studentit.
// Në fund, kodi shfaq totalin e studentëve që kaluan, notën mesatare të studentëve që kaluan, dhe rezultatin maksimal të të gjitha pikëve.
// Nëse pikët e studentit janë të pavlefshme, kodi shfaq një mesazh dhe ndërpret programin.