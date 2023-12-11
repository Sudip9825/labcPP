/* Entrance Preparation System by Sudip Dahal
   C Project */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to display menu and get user's choice
int displayMenu();

// Function to display questions based on the subject and difficulty
void displayQuestions(int, int, FILE *);

FILE *fp;

int main() {
    fp = fopen("entrance.txt", "a+");

    if (fp == NULL) {
        printf("Cannot open file\n");
        exit(1);
    }

    int choice, difficulty, subject;

    do {
        choice = displayMenu();

        switch (choice) {
            case 1: // Mathematics
            case 2: // Physics
            case 3: // English
            case 4: // General Knowledge
                printf("Select difficulty level (1. Easy, 2. Medium, 3. Hard): ");
                scanf("%d", &difficulty);
                displayQuestions(choice, difficulty, fp);
                break;
            case 5: // Quit
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    fclose(fp);
    return 0;
}

// Function to display menu and get user's choice
int displayMenu() {
    int choice;
    printf("Welcome to the Entrance Preparation System\n");
    printf("1. Mathematics\n");
    printf("2. Physics\n");
    printf("3. English\n");
    printf("4. General Knowledge\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to display questions based on the subject and difficulty
void displayQuestions(int subject, int difficulty, FILE *fp) {
    // Define multi-dimensional arrays to store questions and answers
    const char *mathQuestions[][3] = {
        {"What is the square root of 64? ", "Solve for X in the equation 2X+5=17.", "Simplify: (1 + tan^2θ) / (sec^2θ - 1)."},
        {"If a rectangle has a length of 10 units and a width of 6 units, what is its perimeter?", "Simplify (2+5i)+(3-2i)", "Solve for x: 2^(3x) = 32"},
        {"If the cost of one pencil is 15 rupees, how much will 5 pencils cost?", "x+3=7 2x-5=9 solve for x", "Find the sum of the infinite geometric series: 3/5 + 9/25 + 27/125 + ..."},
        {"If a triangle has a base of 12 units and a height of 8 units, what is its area?", "If a=3 and b=4 find the value of 2a*a-3b+5.", "Find the derivative of y = ln(x^2 + 1) with respect to x"},
        {"If a bag contains 80 marbles and you want to divide them equally among 8 friends, how many marbles will each friend receive?", "If Z=2+3i where i is an imaginary unit, find the conjugate of Z?", "Evaluate: tan(45 degrees) + cot(45 degrees)."},
        // Add more math questions for each difficulty level
    };
    const char *physicsQuestions[][3] = {
        {"What is the SI unit of electric charge?", "What is the speed of light in a vacuum?", "Which type of electromagnetic waves has the shortest wavelength?"},
        {"Define Newton's third Law of Motion.", "What is the principle behind the operation of a transformer?", "What is the SI unit of energy?"},
        {"Explain the Doppler effect.", "Which law describes the relationship between the pressure and volume of a gas when the temperature and quantity of gas are held constant?", "What is an example of a vector quantity?"},
        {"Which law of thermodynamics states that energy cannot be created or destroyed, only converted from one form to another?", "What is the SI unit of power?", "What is the phenomenon that causes the sky to appear blue?"},
        {"When an object is submerged in a fluid, it experiences an upward force equal to the weight of the fluid displaced. This principle is known as:", "Which of the following types of waves requires a medium (substance) to propagate through?", "What is the SI unit of frequency?"},
        // Add more physics questions for each difficulty level
    };
    const char *englishQuestions[][3] = {
        {"Identify the subject in the following sentence: The talented musician played the piano beautifully.", "She was proud ____ her accomplishments.", "He apologized ____ his rude behavior."},
        {"The book is ____ the table.", "The hotel is located ____ the city center", "I'm really bad ____ remembering names."},
        {"She walked ____ the park.", "The treasure was buried ____ the old oak tree.", ""},
        {"We'll meet ____ 2:00 PM.", "The painting was hung ____ the wall.", "She was excited ____ the opportunity to travel."},
        {"He is afraid ____ spiders", "He is responsible ____ the project's success.", "-_____ of her broken leg she dances beautifully"},
    };
    const char *generalKnowledgeQuestions[][3] = {
        {"Who composed the national anthem of Nepal?", "Who is known as the Light of Asia?", "What is the national flower of Nepal?"},
        {"What is the capital of Nepal?", "Which river of Nepal is known as the Sorrow of Bihar?", "Who was the first President of Nepal?"},
        {"What is the official language of Nepal?", "Who was the first woman to summit Mount Everest?", "What is the height of Mount Everest?"},
        {"What is the national animal of Nepal?", "Which river is known as the River of Gold?", "Which ancient trade route connected Nepal with Tibet?"},
        {"What is the most widely practiced religion in Nepal?", "Which famous national park in Nepal is home to Bengal tigers?", ""},
    };
    const char *mathAnswers[][3] = {
        {"8", "6", "tanθ"},
        {"32", "5+3i", "2/3"},
        {"75", "7", "25/16"},
        {"48", "11", "(2x)/(x^2 + 1)"},
        {"10", "2-3i", "2"},
        // Add more math answers for each difficulty level
    };
    const char *physicsAnswers[][3] = {
        {"Coulomb", "299,792,458 m/s", "X-ray"},
        {"For every action, there is an equal and opposite reaction.", "A transformer operates on the principle of electromagnetic induction.", "joule"},
        {"The Doppler effect is the change in frequency or wavelength...", "Boyle's Law", "velocity"},
        {"first law", "watt", "Dispersion"},
        {"Archimedes' Principle", "mechanical wave", "hertz"},
        // Add more physics answers for each difficulty level
    };
    const char *englishAnswers[][3] = {
        {"musician", "of", "for"},
        {"on", "in", "at"},
        {"through", "beneath", "on"},
        {"at", "on", "about"},
        {"of", "for", "despite"},
    };
    const char *generalKnowledgeAnswers[][3] = {
        {"Pradeep Kumar Rai (Byakul Maila)", "lord buddha", "rhododendron"},
        {"Kathmandu", "kosi", "Dr. Ram Bharan Yadav"},
        {"Nepali", "Junko Tabei (from Japan)", "8848m"},
        {"cow", "karnali", "Trans-Himalayan Trade Route"},
        {"Hinduism", "Chitwan National Park", "Phewa Lake"},
    };
    int numQuestions;

    switch (subject) {
        case 1: // Mathematics
            numQuestions = sizeof(mathQuestions) / sizeof(mathQuestions[0]);
            break;
        case 2: // Physics
            numQuestions = sizeof(physicsQuestions) / sizeof(physicsQuestions[0]);
            break;
        case 3: // English
            numQuestions = sizeof(englishQuestions) / sizeof(englishQuestions[0]);
            break;
        case 4: // General Knowledge
            numQuestions = sizeof(generalKnowledgeQuestions) / sizeof(generalKnowledgeQuestions[0]);
            break;
        default:
            printf("Invalid subject choice.\n");
            return;
    }

    if (difficulty < 1 || difficulty > 3) {
        printf("Invalid difficulty level.\n");
        return;
    }

    // Display the selected questions based on difficulty
    for (int i = 0; i < numQuestions; ++i) {
        if (subject == 1) {
            printf("Q%d: %s\n", i + 1, mathQuestions[i][difficulty - 1]);
        } else if (subject == 2) {
            printf("Q%d: %s\n", i + 1, physicsQuestions[i][difficulty - 1]);
        } else if (subject == 3) {
            printf("Q%d: %s\n", i + 1, englishQuestions[i][difficulty - 1]);
        } else if (subject == 4) {
            printf("Q%d: %s\n", i + 1, generalKnowledgeQuestions[i][difficulty - 1]);
        } else {
            // Handle other subjects here
            printf("Q%d: [Question not available for this subject]\n", i + 1);
        }

        // Get the user's answer
        char userAnswer[100];
        printf("Your answer: ");
        scanf("%s", userAnswer);

        // Compare the user's answer with the correct answer
        const char *correctAnswer;
        if (subject == 1) {
            correctAnswer = mathAnswers[i][difficulty - 1];
        } else if (subject == 2) {
            correctAnswer = physicsAnswers[i][difficulty - 1];
        } else if (subject == 3) {
            correctAnswer = englishAnswers[i][difficulty - 1];
        } else if (subject == 4) {
            correctAnswer = generalKnowledgeAnswers[i][difficulty - 1];
        } else {
            // Handle other subjects here
            continue;
        }

        if (strcmp(userAnswer, correctAnswer) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is: %s\n", correctAnswer);
            fprintf(fp, "Q%d: %s\nYour Answer: %s\nCorrect Answer: %s\n\n", i + 1,
                    (subject == 1) ? mathQuestions[i][difficulty - 1] :
                    (subject == 2) ? physicsQuestions[i][difficulty - 1] :
                    (subject == 3) ? englishQuestions[i][difficulty - 1] :
                    (subject == 4) ? generalKnowledgeQuestions[i][difficulty - 1] : "N/A",
                    userAnswer, correctAnswer);
        }

        printf("\n");
    }
}


