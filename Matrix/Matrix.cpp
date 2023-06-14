// 2
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <array>

int main() {
    const int nrows = 3;
    const int ncols = 3;
    srand(time(NULL));

    std::array<std::array<int, ncols>, nrows> mat;

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            mat[i][j] = rand() % 100;
            std::cout << mat[i][j] << "  ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            mat[i][j] *= mat[i][1];
            std::cout << mat[i][j] << "  ";
        }
        std::cout << "\n";
    }

    return 0;
}

// 4
#include <iostream>
#include <array>
#include <stdlib.h>
#include <ctime>

int main() {
    const int nrows = 4;
    const int ncols = 4;
    srand(time(NULL));
    int summ = 0;

    std::array<std::array<int, ncols>, nrows> mat;

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            mat[i][j] = rand() % 200 - 100;
            std::cout << mat[i][j] << "  ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for (int i = 0; i < nrows; i++) {
        for (int j = i; j < ncols; j++) { // ïðîñìàòðèâàåì ýëåìåíòû íà è âûøå ãëàâíîé îñè
            if (j % 2 == 0 && mat[i][j] > 0) { // ïðîâåðÿåì, ÷òî ñòîëáåö ÷åòíûé è ÷èñëî ïîëîæèòåëüíîå
                summ += mat[i][j];
            }
        }
    }
    std::cout << summ;

    return 0;
}

//7
#include <iostream>
#include <array>
#include <stdlib.h>
#include <ctime>

int main() {
    srand(time(NULL));
    const int days = 7;

    std::array<std::array<int, days>, 2> mat;
    
    for (int i = 0; i < days; i++){
        for (int j = 0; j < 2; j++){
            mat[i][j] = rand() % 50;
             std::cout << mat[i][j] << " ";
        }
         std::cout << "\n";
    }

    int max_wind_speed = 0;
    int max_rainfall = 0;
    int max_rainfall_index = -1;
    int max_rwind_speed_index = -1;
    
         std::cout <<  "\n";
    
  for (int i = 0; i < days; i++) {
    int wind_speed = mat[i][1];
    int rainfall = mat[i][0];
    
     // std::cout << i << " " << rainfall << " " << wind_speed << "\n";


    if (wind_speed > max_wind_speed) 
     {
      max_wind_speed = wind_speed;
      max_rwind_speed_index = i;}
      
    if (rainfall > max_rainfall) 
    {
      max_rainfall = rainfall;
      max_rainfall_index = i;} 
      
      std::cout << i << " " << max_wind_speed << " " << max_rainfall << "\n";
      
    }
  
    if (max_rwind_speed_index == max_rainfall_index) {std::cout << "Был ураган в день " << max_rainfall_index << std::endl;}
    else {std::cout << "Урагана не было "    << max_rainfall_index << " " << max_rwind_speed_index << " " << max_wind_speed << " " << max_rainfall << std::endl;}

  return 0;
}

// 9b
#include<iostream>
#include<array>
#include<time.h>

struct Robot
{
    int power;
    int speed;
};

const int lines = 7;
const int colums = 7;

void func(std::array<std::array<Robot, colums>, lines> dask)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            std::cout << dask[j][i].power << ";" << dask[j][i].speed << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::array<std::array<Robot, colums>, lines> dask;
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            std::cout << "Power: ";
            std::cin >> dask[j][i].power;
            std::cout << "Speed: ";
            std::cin >> dask[j][i].speed;
        }
    }
    std::cout << std::endl;
    func(dask);
    return 0;
}

//10(2)

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <array>

const int nrows = 3;
const int ncols = 3;

int normal(std::array<std::array<int,ncols>, nrows> mat){
    std::array<int,3> summ;
    int num_summ;
    int num_max = -1;
    for(int i = 0; i < nrows; i++)
    {
        num_summ = 0;
        for(int j = 0; j < ncols; j++)
        {
            num_summ += abs(mat[j][i]);
        }
        summ[i] = num_summ;
    }

    for(int a=0;a<3;a++)
    {
        if(summ[a]>num_max)
        {
            num_max = summ[a];
        }
    }

    return num_max;
}


int main(){
    srand(time(NULL));

    std::array<std::array<int, ncols>, nrows> mat;
    
    for (int i = 0; i < nrows; i++){
        for (int j = 0; j < ncols; j++){
            mat[i][j] = rand() % 10;
            std::cout << mat[i][j] << "  ";
        }
        std::cout << "\n";
    }
    
    std::cout << "\n";
    
    int second = 1;
    
    for (int i = 0; i < nrows; i++){
        second = mat[i][1];
        for (int j = 0; j < ncols; j++){
            mat[i][j] *= second;
            std::cout << mat[i][j] << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n" << "Normal: " << normal(mat);
    
    return 0;
}

//11

#include <iostream>
#include <array>
#include <stdlib.h>
#include <ctime>
const int nrows = 3, ncols = 3;

void summMat(std::array<std::array<int, ncols>, nrows> mat1, std::array<std::array<int, ncols>, nrows> mat2) {
    std::cout << "Cóììà\n";
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            std::cout << mat1[i][j] + mat2[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void minMat(std::array<std::array<int, ncols>, nrows> mat1, std::array<std::array<int, ncols>, nrows> mat2) {
    std::cout << "Ðàçíîñòü\n";
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            std::cout << mat1[i][j] - mat2[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void ymnozhMat(std::array<std::array<int, ncols>, nrows> mat1, std::array<std::array<int, ncols>, nrows> mat2) {
    std::array<std::array<int, ncols>, nrows> res;
    std::cout << "Óìíîæåíèå\n";
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            for (int k = 0; k < nrows; k++) {
                res[i][j] = mat1[i][k] * mat2[k][j];
            }
        }
    }
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void trancMat(std::array<std::array<int, ncols>, nrows> mat) {
    std::array<std::array<int, ncols>, nrows> res;
    std::cout << "Òðàíñïîíèðîâàíèå\n";
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            res[i][j] = mat[j][i];
        }
    }
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
}


int main() {
    std::array<std::array<int, ncols>, nrows> mat1;
    srand(time(NULL));
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            mat1[i][j] = rand() % 10;
            std::cout << mat1[i][j] << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    std::array<std::array<int, ncols>, nrows> mat2;
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            mat2[i][j] = rand() % 10;
            std::cout << mat2[i][j] << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    summMat(mat1, mat2);
    minMat(mat1, mat2);
    ymnozhMat(mat1, mat2);
    trancMat(mat1);
    trancMat(mat2);

    return 0;
}
//12

#include <iostream>
#include <array>
#include <ctime>
int main() {
    const int ncols = 5;
    const int nrows = 5;
    int black = 0;
    std::array <std::array <int, ncols>, nrows> mat;
    srand(time(NULL));
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            mat[i][j] = rand() % 2;
            if (mat[i][j] == 0) {
                black++;
            }
        }
    }
    std::cout << " matric" << std::endl;
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;

    }
    std::cout << black;
    return 0;
}
