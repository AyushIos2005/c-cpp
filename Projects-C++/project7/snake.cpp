#include <bits/stdc++.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

Direction dir;
bool GameOver;
const int height = 20, width = 20;

int headX, headY, fruitX, fruitY, score;
int tail_len;
deque<int> tailX, tailY;

void setup();
void draw();
void input();
void logic();

void setup() {
    GameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height / 2;  // Fixed: was width/2, should be height/2
    fruitX = rand() % width;
    fruitY = rand() % height;  // Fixed: was rand()%width, should be %height
    score = 0;
    tail_len = 0;
    tailX.clear();
    tailY.clear();
    srand(time(NULL));  // Added for random fruit placement
}

void draw() {
    system("cls");

    // Top Border
    cout << "\t\t";
    for (int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        cout << "\t\t";
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1)
                cout << "#";  // Wall border
            else if (i == headY && j == headX)
                cout << "O";  // Snake head
            else if (i == fruitY && j == fruitX)
                cout << "*";  // Fruit
            else {
                bool printTail = false;
                for (size_t k = 0; k < tailX.size(); k++) {  // Fixed: use tailX.size() instead of tail_len
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";  // Snake tail
                        printTail = true;
                        break;  // Added break for efficiency
                    }
                }
                if (!printTail)
                    cout << " ";  // Empty space
            }
        }
        cout << endl;
    }

    // Bottom Border
    cout << "\t\t";
    for (int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;

    // Score Display
    cout << "\n\t\tScore : " << score << endl;
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                if (dir != RIGHT) dir = LEFT;  // Prevent reversing into self
                break;
            case 'd':  // Fixed: was 'b', assuming 'd' for right (common in some layouts, but code had 'b')
                if (dir != LEFT) dir = RIGHT;
                break;
            case 'w':  // Fixed: was 'c', changed to 'w' for up (standard WASD)
                if (dir != DOWN) dir = UP;
                break;
            case 's':  // Fixed: was 'd', changed to 's' for down
                if (dir != UP) dir = DOWN;
                break;
        }
    }
}

void logic() {
    if (dir == STOP) return; // Prevents auto game over at start

    // Add current head to front of tail
    tailX.push_front(headX);
    tailY.push_front(headY);

    // Move head
    switch (dir) {
        case LEFT: headX--; break;
        case RIGHT: headX++; break;
        case UP: headY--; break;
        case DOWN: headY++; break;
        default: break;
    }

    // Wall wrapping
    if (headX >= width) headX = 0;
    else if (headX < 0) headX = width - 1;
    if (headY >= height) headY = 0;
    else if (headY < 0) headY = height - 1;

    // Self collision
    for (size_t i = 1; i < tailX.size(); i++) { // start from 1 (skip head index)
        if (tailX[i] == headX && tailY[i] == headY)
            GameOver = true;
    }

    // Eating fruit
    if (headX == fruitX && headY == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    } else {
        // Remove tail end
        tailX.pop_back();
        tailY.pop_back();
    }
}
void discaimler(){
    cout<<"\t\t\t DISCAMLER\t\t\t"<<endl;
    cout<<" | Key   | Movement  | Hindi Meaning      |\n";
    cout<<" | ----- | --------- | ------------------ |\n";
    cout<<" | **W** | Up (↑)    | Upar move karna    |\n";
    cout<<" | **A** | Left (←)  | Left / Baaye jana  |\n";
    cout<<" | **S** | Down (↓)  | Neeche move karna  |\n";
    cout<<" | **D** | Right (→) | Right / Daaye jana |\n";
    cout<<"Character movement / Snake movement / Player control"<<endl;
    cout << "Continue.....\n";

    for (int i = 10; i >= 1; i--) {
        cout << "\rStarting in: " << i << " seconds "<<endl;
        Sleep(1000); // wait 1 second
    }
}

int main() {
    discaimler();
    char start;
    cout << "--------------------------------------------" << endl;
    cout << "\t\t\t::Snake Raja::\t\t\t" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Press 's' to start : ";
    cin >> start;
    if (start == 's') {
        cout << "Start Game!" << endl;
        setup();
        while (!GameOver) {
            draw();
            input();
            logic();
            Sleep(100);  // Adjusted delay for better playability
        }
        cout << "Game Over! Final Score: " << score << endl;  // Added game over message
    }
    return 0;
}
