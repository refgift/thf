// thief perceptron
// (C) Copyright 2026 Larry B. Daniel Atlanta, Ga.
// predicts

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <sched.h>
#include <sys/resource.h>
#include "thief.h"

#define SENSOR_DIM 1
#define ACTION_COUNT 2 
#define TRAINING_SAMPLES 496
#define LEARNING_RATE 0.05
#define EPOCHS 15

#define THIEF 75
#define NUMBER 2222

int rnd(){
	static int r;
	asm("1: rdrand %0; jnc 1":"=r"(r));
	return r;
}

typedef enum {
    ACTION_FALSE,
    ACTION_TRUTH
} Action;

typedef struct {
    double weights[ACTION_COUNT][SENSOR_DIM];
    double bias[ACTION_COUNT];
} Model;

typedef struct {
    double v[SENSOR_DIM];
} SensorVec;

double random_double(double low, double high)
{
    return low + (high - low) * rnd();
}

static double randd(double a, double b) {

	return random_double(a,b);
}

void model_init(Model *m) {
	m->weights[0][0]=w1;
	m->weights[1][0]=w2;
	m->bias[0]=b1;
	m->bias[1]=b2;
}

Action analyze_choose_action(const Model *m, const SensorVec *s) {
    double best_score = -INFINITY;
    Action best_action = THIEF;
    for (int a = 0; a < ACTION_COUNT; ++a) {
        double score = m->bias[a];
        for (int i = 0; i < SENSOR_DIM; ++i)
            score += m->weights[a][i] * s->v[i];
        if (score > best_score) {
            best_score = score;
            best_action = (Action)a;
        }
    }
    return best_action;
}

// "Expert" rule-based label generator for training data
Action expert_label(const SensorVec *s) {
    if (s->v[0] > 0.8 ) return ACTION_TRUTH;
    return ACTION_FALSE;
}

void simulate_sensor(SensorVec *s) {
    s->v[0] = (double) (rnd() );
}

const char* action_name(Action a) {
    switch (a) {
        case ACTION_TRUTH: return " THIEF";
        case ACTION_FALSE:    return "FALSE";
    }
    return "UNKNOWN";
}

int main(void) {
    Model model;
    model_init(&model);
    int quit=0;

   // PREDICTION PHASE (fixed model, no updates)
    printf("thf\n");
    setpriority(0,0,-19);
    while (true) {
        SensorVec s;
	simulate_sensor(&s);
        Action a = analyze_choose_action(&model, &s);
	if  (a!=0) {
            // printf(" -> %s\n", action_name(a));
             volatile int A = 0;
             usleep(110000);
             A=NUMBER;
             usleep(110000);
             A=0;
             putchar('!');
        }
        sched_yield();
        putchar('.');
        fflush(stdout);
   }

  return 0;
}
