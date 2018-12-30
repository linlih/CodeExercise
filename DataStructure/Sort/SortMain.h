#define ARRAYSIZE 1000

int main(int argc, char const *argv[])
{
    Randomize();

    int listsize = 1000;
    int *array;
    array = new int[ARRAYSIZE];
    int i;

    for (i = 0; i < ARRAYSIZE; i++) {
        array[i] = Random(1000);
    }
    Print(array, listsize);

    Settime();

    sort(array, listsize);

    cout << "Sort with list size " << listsize << ", array size " << ARRAYSIZE << ", and threshold " << THRESHOLD << ": " << Gettime()<< " seconds\n";
    
    cout << "After sorting : " << endl;
    Print(array, listsize);

    return 0; 
}