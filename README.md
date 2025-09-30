[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/T_SwjO2j)
# Identity
Name : Muhammad Akhsan Araya Choirunnas

# AI usage
Explain how you use the AI to solve the assignment. Put all ***your used queries*** in this section & what kind of AI are you using. Declare not using AI if you didn't do this.

I use AI to find the problems existing in the algorithm, such as unexpected lines forming to the inside and tangent not fount correctly by asking to use debug in the qt. I also used AI for the UI so that the canvas doesn't pverlapped with the UI that makes the buttons below the canvas and unable to be clicked. 

in SlowConvexHull/linewidget.cpp:
if (next_point_index == -1) {
            qDebug() << "Hull chain failed to find the next point.";
            break;
        }

in IncrementalConvexHull/linewidget.cpp:
if (i_start == -1 || i_end == -1) {
            qDebug() << "Error: Tangent indices not found correctly.";
            continue;
        }  

in both/DrawingWindow.cpp:

mainLayout->addStretch();

The AI I use is Gemini from google.



# Collaboration usage
Explain how you are ***using others*** to complete the assignment in this section. Are they simply copying, learn the ideas, learn how to adapt the AI or anything involving the process. State the people if any & Please be elaborate. Declare self tought if you solved this by yourself.

I self thought to learn how to adapt using AI by learning the algorithm and the right prompt for better answers to Gemini's evolving nature.
And for the algorithm, I learn from this channel on youtube: Best Bangla Solutions for the video and also geeksforgeeks for having ideas on how this algorithm works

# Commit Rules
Use .gitignore to stripe any binaries from the resulting build before commit.  If you cloned directly from the template, you are safe. 

# Due Time
September 30th, 2025. 23: 59 WIB
