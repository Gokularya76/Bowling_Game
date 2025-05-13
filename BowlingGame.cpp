#include <iostream>
#include <vector>

using namespace std;

class BowlingGame {
private:
    vector<int> rolls;

public:
    void roll(int pins) {
        rolls.push_back(pins);
    }

    int score() {
        int totalScore = 0;
        int frameIndex = 0;

        for (int frame = 0; frame < 10; frame++) {
            if (isStrike(frameIndex)) {
                // Strike: 10 + next two rolls
                totalScore += 10 + strikeBonus(frameIndex);
                frameIndex += 1;
            } else if (isSpare(frameIndex)) {
                // Spare: 10 + next roll
                totalScore += 10 + spareBonus(frameIndex);
                frameIndex += 2;
            } else {
                // Normal frame
                totalScore += frameScore(frameIndex);
                frameIndex += 2;
            }
        }

        return totalScore;
    }

private:
    bool isStrike(int index) {
        return rolls[index] == 10;
    }

    bool isSpare(int index) {
        return rolls[index] + rolls[index + 1] == 10;
    }

    int strikeBonus(int index) {
        return rolls[index + 1] + rolls[index + 2];
    }

    int spareBonus(int index) {
        return rolls[index + 2];
    }

    int frameScore(int index) {
        return rolls[index] + rolls[index + 1];
    }
};

// Example usage
int main() {
    BowlingGame game;

    // Example input from image: 1 4 | 4 5 | 6 / | 5 / | X | 0 1 | 7 / | 6 / | X | 2 6
    vector<int> input = {1,4,4,5,6,4,5,5,10,0,1,7,3,6,4,10,2,6};

    for (int pins : input) {
        game.roll(pins);
    }

    cout << "Total Score: " << game.score() << endl;

    return 0;
}
