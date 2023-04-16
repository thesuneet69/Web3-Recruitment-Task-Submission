#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Speed{
    int sx; int sy; int sz;
};
typedef struct Speed S;

typedef struct {
    char* make;
    char* model;
    int year;
    S speed;
    int x;
    int y;
    int z;
} Car;


void accelerate(Car* car, int ax, int ay, int az) {
    car->speed.sx += ax;
    car->speed.sy += ay;
    car->speed.sz += az;
}

void brake(Car* car, int bx, int by, int bz) {
    car->speed.sx -= bx;
    car->speed.sy -= by;
    car->speed.sz -= bz;
}

void move(Car* car) {
    car->x += car->speed.sx;
    car->y += car->speed.sy;
    car->z += car->speed.sz;
}

int detect_collision(Car* car1, Car* car2) {
    double distance = sqrt(pow((car1->x - car2->x), 2) + pow((car1->y - car2->y), 2) + pow((car1->z - car2->z), 2));
    if (distance == 0) { // assuming collision distance of 10 units
        return 1;
    } else {
        return 0;
    }
}

double time_to_collision(Car* car1, Car* car2) {
    double speedcar1 = sqrt(pow((car1->speed.sx), 2) + pow((car1->speed.sy), 2) + pow((car1->speed.sz), 2)); 
    double speedcar2 = sqrt(pow((car2->speed.sx), 2) + pow((car2->speed.sy), 2) + pow((car2->speed.sz), 2)); 
    double relative_speed = fabs(speedcar1 - speedcar2);
    double distance = sqrt(pow((car1->x - car2->x), 2) + pow((car1->y - car2->y), 2) + pow((car1->z - car2->z), 2));
    if (relative_speed == 0) {
        return -1; // cars are moving at the same speed
    } else {
        double time = distance/(relative_speed);
        return time;
    }
}

int main() {
    int spx1, spy1, spz1, spx2, spy2, spz2, cx1, cy1, cz1, cx2, cy2, cz2;
    
    printf("Enter speed with co-ordinates of car1: ");
    scanf("%d%d%d", &spx1, &spy1, &spz1);
    
    printf("Enter co-ordinates of car1: ");
    scanf("%d%d%d", &cx1, &cy1, &cz1);

    printf("Enter speed with co-ordinates of car2: ");
    scanf("%d%d%d", &spx2, &spy2, &spz2);
    
    printf("Enter co-ordinates of car2: ");
    scanf("%d%d%d", &cx2, &cy2, &cz2);

    S spp1; spp1.sx = spx1; spp1.sy = spy1; spp1.sz = spz1; 
    S spp2; spp2.sx = spx2; spp2.sy = spy2; spp2.sz = spz2; 
    
    Car car1 = {"Hyundai", "Alto", 2020, spp1, cx1, cy1, cz1};
    Car car2 = {"Maruti", "Creta", 2021, spp2, cx2, cy2, cz2};
    
    int ax, ay, az, bx, by, bz;
   
    /*printf("Enter acceleration of car with 3 components: ");
    scanf("%d %d %d", &ax, &ay, &az);

    printf("Enter braking of car with 3 components: ");
    scanf("%d %d %d", &bx, &by, &bz);*/
    
    int dec = 0; char dec2;
    printf("Which car do you wanna accelerate or brake ?");
    scanf(" %d", &dec);
    if(dec == 1)
    {
        printf("Press A if you wanna acc, B if you wanna break.");
        scanf(" %c", &dec2);
        if(dec2 == 'A')
        {
            printf("Enter acceleration with 3 components: ");
            scanf("%d %d %d", &ax, &ay, &az);
            accelerate(&car1, ax, ay, az);
        }
        else{
            printf("Enter braking with 3 components: ");
            scanf("%d %d %d", &bx, &by, &bz);
            brake(&car1, bx, by, bz);

        }
    }
    else
    {
        printf("Press A if you wanna acc, B if you wanna break");
        scanf(" %c", &dec2);
        if(dec2 == 'A')
        {
            printf("Enter acceleration with 3 components: ");
            scanf("%d %d %d", &ax, &ay, &az);
            accelerate(&car2, ax, ay, az);
        }
        else{
            printf("Enter braking with 3 components: ");
            scanf("%d %d %d", &bx, &by, &bz);
            brake(&car2, bx, by, bz);

        }
    }

    double time_to_collision1 = time_to_collision(&car1, &car2);

    move(&car1);
    move(&car2);

    int collision = detect_collision(&car1, &car2);
    //printf("Collision: %d\n", collision);
    if(collision == 0){
    printf("They will not collide.");
    return 0;
    }
    else{
        printf("They will collide!\n");
    }
    

    
    printf("Time to collision: %.2lf\n", time_to_collision1);

    return 0;
}
    