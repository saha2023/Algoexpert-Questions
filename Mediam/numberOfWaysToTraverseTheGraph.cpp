using namespace std;

int factorial(int num){
    int result = 1;
    for(int n=2;n<=num;n++){
        result *= n;
    }
    return result;
}
int numberOfWaysToTraverseGraph(int width, int height) {
    int stepstocornerX = width - 1;
    int stepstocornerY = height - 1;
    int numerator = factorial(stepstocornerX + stepstocornerY);
    int denominator = factorial(stepstocornerX) * factorial(stepstocornerY);
    return numerator / denominator;
    return -1;
}
