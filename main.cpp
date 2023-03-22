/**************************
 * Includes
 *
 **************************/
#include <windows.h>
#include "glut.h"
#include "graph.h"
#include <stdio.h>
#include <math.h>

int basculex = 1;
int basculey = 1;
int basculez = 1;
int bascule_Menu = 0;
float coeff_translatX;
float coeff_translatY;

float Distance(float x, float y) {
    return abs(x - y);
}

void myKey(int c)
{
    coeff_translatX = Distance(get_A(), get_B()) / 50;
    coeff_translatY = Distance(get_C(), get_D()) / 50;
    if (bascule_Menu == 0) {
        if (c == 'q') {
            basculex = -1;
            if (get_X0() >= -10000) {
                set_TranslatX(get_TranslatX() + coeff_translatX * basculex);
                basculex = 0;
            }
        }
        if (c == 'd') {
            basculex = 1;
            if (get_X0() <= 10000) {
                set_TranslatX(get_TranslatX() + coeff_translatX * basculex);
                basculex = 0;
            }
        }
        if (c == 's') {
            basculey = -1;
            if (get_Y0() >= -10000) {
                set_TranslatY(get_TranslatY() + coeff_translatY * basculey);
                basculey = 0;
            }
        }
        if (c == 'z') {
            basculey = 1;
            if (get_Y0() <= 10000) {
                set_TranslatY(get_TranslatY() + coeff_translatY * basculey);
                basculey = 0;
            }
        }
        if (c == '=') {
            basculez = 1;
            set_Zoom(get_Zoom() * 0.95);
            basculez = 0;
        }
        if (c == '-') {
            set_Zoom(get_Zoom() / 0.95);
            basculez = 0;
        }
        if (c == 'r') {
            set_TranslatX(0);
            set_TranslatY(0);
            set_Zoom(1);
        }
    }
    if (bascule_Menu == 1) {
        if (c == 'c') {
            if (get_toggle() == 1) {
                set_toggle(0);
            }
            else { set_toggle(get_toggle() + 1); }
        }
    }
    if (c == 'm') {
    bascule_Menu^= 1;
    }
}


// affichage du graph, du menu (avec bascule_Menu) et des coordonnees du curseur

void Draw(float x[], float y[]) {
    
   //tracé de la fonction
    setcolor(0.0F, 0.0F, 1.0F);
    for (int i = 0; i < 99; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    
    //Affichage des Coordonnées du curseur
    char valeurX0[100]; 
    char valeurY0[100];  
    sprintf(valeurX0, "X=%f", get_X0()); 
    sprintf(valeurY0, "Y=%f", get_Y0());
    setcolor(0,0,0);
    outtextxy(get_X0() + abs(get_B() - get_X0()) * 0.70, get_Y0() + abs(get_D() - get_Y0()) * 0.90, valeurX0);
    outtextxy(get_X0() + abs(get_B() - get_X0()) * 0.70, get_Y0() + abs(get_D() - get_Y0()) * 0.80, valeurY0);

    //Affichage du menu

    if (bascule_Menu == 1) {
        float Dx;
        float Dy;
        Dx = Distance(get_X0(), get_B());
        Dy = Distance(get_Y0(), get_D());
        setcolor(0.27F, 0.27F, 0.27F); 
        bar(get_X0() - Dx * (1.9 / 5), get_Y0() - Dy * (3.1 / 5), get_X0() + Dx * (2.46 / 5), get_Y0() + Dy * (2.9 / 5)); 
        setcolor(0.95F, 0.95F, 0.95F);
        bar(get_X0() - Dx * (2.0/ 5), get_Y0() - Dy * (3.0/ 5), get_X0() + Dx * (2.4/ 5), get_Y0() + Dy * (3.0/ 5));
        setcolor(0.0F, 0.0F, 0.0F);
        outtextxy(get_X0() - Dx*(2.0/5), get_Y0() + Dy * (3.2 / 5), "MENU");
        outtextxy(get_X0() - Dx * (1.9 / 5), get_Y0() + Dy * (2.7 / 5), "COMMANDS :");
        outtextxy(get_X0() - Dx * (1.8 / 5), get_Y0() + Dy * (2.2 / 5), "z : up");
        outtextxy(get_X0() - Dx * (1.8 / 5), get_Y0() + Dy * (1.7 / 5), "s : down");
        outtextxy(get_X0() - Dx * (1.8 / 5), get_Y0() + Dy * (1.2 / 5), "q : left");
        outtextxy(get_X0() - Dx * (1.8 / 5), get_Y0() + Dy * (0.7 / 5), "d : right");
        outtextxy(get_X0() - Dx * (1.8 / 5), get_Y0() + Dy * (0.2 / 5), "+ : zoom in");
        outtextxy(get_X0() - Dx * (1.8 / 5), get_Y0() + Dy * (-0.3 / 5), "- : zoom out");
        outtextxy(get_X0() - Dx * (1.8 / 5), get_Y0() + Dy * (-0.3 / 5), "- : zoom out");
        outtextxy(get_X0() - Dx * (1.8 / 5), get_Y0() + Dy * (-0.8 / 5), "r : reset position");
        outtextxy(get_X0() - Dx * (1.8 / 5), get_Y0() + Dy * (-1.3 / 5), "m : menu");
        outtextxy(get_X0() - Dx * (1.8 / 5), get_Y0() + Dy * (-1.8 / 5), "c : change cursor ");
    }              
}
int main(int ac, char* av[])
{
    float x[100] = {-25, -24.5, -24.0, -23.5, -23.0, -22.5, -22.0, -21.5, -21.0, -20.5, -20.0, -19.5, -19.0, -18.5, -18.0, -17.5, -17.0, -16.5, -16.0, -15.5, -15.0, -14.5, -14.0, -13.5, -13.0, -12.5, -12.0, -11.5, -11.0, -10.5, -10.0, -9.5, -9.0, -8.5, -8.0, -7.5, -7.0, -6.5, -6.0, -5.5, -5.0, -4.5, -4.0, -3.5, -3.0, -2.5, -2.0, -1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0, 8.5, 9.0, 9.5, 10.0, 10.5, 11.0, 11.5, 12.0, 12.5, 13.0, 13.5, 14.0, 14.5, 15.0, 15.5, 16.0, 16.5, 17.0, 17.5, 18.0, 18.5, 19.0, 19.5, 20.0, 20.5, 21.0, 21.5, 22.0, 22.5, 23.0, 23.5, 24.0, 24.5};
    float y[100] = { -15600, -14681.125, -13799.0, -12952.875, -12142.0, -11365.625, -10623.0, -9913.375, -9236.0, -8590.125, -7975.0, -7389.875, -6834.0, -6306.625, -5807.0, -5334.375, -4888.0, -4467.125, -4071.0, -3698.875, -3350.0, -3023.625, -2719.0, -2435.375, -2172.0, -1928.125, -1703.0, -1495.875, -1306.0, -1132.625, -975.0, -832.375, -704.0, -589.125, -487.0, -396.875, -318.0, -249.625, -191.0, -141.375, -100.0, -66.125, -39.0, -17.875, -2.0, 9.375, 17.0, 21.625, 24.0, 24.875, 25.0, 25.125, 26.0, 28.375, 33.0, 40.625, 52.0, 67.875, 89.0, 116.125, 150.0, 191.375, 241.0, 299.625, 368.0, 446.875, 537.0, 639.125, 754.0, 882.375, 1025.0, 1182.625, 1356.0, 1545.875, 1753.0, 1978.125, 2222.0, 2485.375, 2769.0, 3073.625, 3400.0, 3748.875, 4121.0, 4517.125, 4938.0, 5384.375, 5857.0, 6356.625, 6884.0, 7439.875, 8025.0, 8640.125, 9286.0, 9963.375, 10673.0, 11415.625, 12192.0, 13002.875, 13849.0, 14731.125 };
    InitGraph(ac, av, "fonction", 1280, 720, Draw, myKey, x, y);
    return 0;

}
