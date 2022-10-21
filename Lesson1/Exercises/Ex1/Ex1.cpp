/**
 * @file Ex1.cpp
 * @author Andrea Bioddo (anbioddo@edu.aau.at)
 * @brief 
 * @version 0.1
 * @date 2022-10-20
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief A matrix is an integer array of array. This class has 
 * friend methods that allow the user to print and to multply two matrixs.
 * There are also some public methods, needed to create, set and get some information about the matrix.
 */
class Matrix{
    public:
        Matrix(int r, int c);
        friend Matrix multply(Matrix a, Matrix b);
        friend void printMatrix(Matrix a);
        void setElem(int r, int c, int value);
        int getElem(int r, int c);
        int getNumRow();
        int getNumCol();
    
    private:
        int numRow;
        int numCol;
        int** matrix;
};

/**
 * @brief Print a matrix
 * 
 */
void printMatrix(Matrix a){
    for(int r=0; r<a.getNumRow(); r++){
        for(int c=0; c<a.getNumCol(); c++){
            cout << a.getElem(r,c) << " ";
        }
        cout << endl;
    }
}

/**
 * @brief Construct a new Matrix:: Matrix object. Using the parameters, it crate a new empty matrix rxc
 * 
 * @param r number of the rows
 * @param c number of the cols
 */
Matrix::Matrix(int r, int c){
    if(r < 0 || c < 0){
        cout << "Operation not allowed: the number of the rows and the cols cannot be negative" << endl;
        exit(EXIT_FAILURE);
    }
    int i, j;
    numRow = r;
    numCol = c;
    matrix = (int**)malloc(sizeof(int)*numCol*numRow);
    for(i=0; i<numRow; i++){
        matrix[i] = (int*)malloc(sizeof(int)*numCol);
        for(j=0; j<numCol; j++){
            matrix[i][j] = 0;
        }
    }
}

/**
 * @brief return the number of the matrix's rows
 * 
 */
int Matrix::getNumRow(){
    return numRow;
}

/**
 * @brief return the number of the matrix's cols
 * 
 */
int Matrix::getNumCol(){
    return numCol;
}

/**
 * @brief set a given value in the position rxc
 * 
 * @param r row
 * @param c col
 * @param value value 
 */
void Matrix::setElem(int r, int c, int value){
    matrix[r][c] = value;
}

/**
 * @brief return the elem in position rxc
 * 
 * @param r row
 * @param c col
 */
int Matrix::getElem(int r, int c){
    return matrix[r][c];
}

/**
 * @brief Return a new matrix that is the resultant of the product between matrix a and b
 * 
 * @param a first matrix
 * @param b second matrix
 */
Matrix multply(Matrix a, Matrix b){
    if(a.getNumCol() != b.getNumRow()){
        cout << "Operation not allowed" << endl;
        return a;
    }
    Matrix res(a.getNumRow(), b.getNumCol());
    for(int i=0; i<res.getNumRow(); i++){
        for(int j=0; j<res.getNumRow(); j++){
            res.setElem(i,j,0);
            for(int k=0; k<b.getNumRow() ;k++){
                res.setElem(i,j,res.getElem(i,j)+a.getElem(i,k)*b.getElem(k,j));
            }
        }
    }
    return res;  
}

int main(){
    Matrix m(3,2);
    Matrix f(2,3);
    clock_t start, end;

    m.setElem(0,0,1);
    m.setElem(0,1,1);
    m.setElem(1,0,2);
    m.setElem(1,1,2);
    m.setElem(2,0,3);
    m.setElem(2,1,3);
    
    f.setElem(0,0,1);
    f.setElem(0,1,1);
    f.setElem(0,2,1);
    f.setElem(1,0,2);
    f.setElem(1,1,2);
    f.setElem(1,2,2);

    cout << "First matrix:" << endl;
    printMatrix(m);
    cout << "\nSecond matrix:" << endl;
    printMatrix(f);
    start = clock();
    Matrix c = multply(m,f);
    end = clock();
    cout << "\nResult matrix:" << endl;
    printMatrix(c);
    cout << "Result found in: " << (end-start)/10000 << " milliseconds." << endl;
    exit(EXIT_SUCCESS);
}