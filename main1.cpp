/***************************************************************************/
/*                                                                         */
/* 234218 Data DSs 1, Spring 2015                                     */
/*                                                                         */
/* Homework : Wet 1                                                        */
/*                                                                         */
/***************************************************************************/

/***************************************************************************/
/*                                                                         */
/* File Name : main1.cpp                                                   */
/*                                                                         */
/* Holds the "int main()" function and the parser of the shell's           */
/* command line.                                                           */
/***************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library1.h"
#include <iostream>
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

/* The command's strings */
typedef enum {
	NONE_CMD = -2,
	COMMENT_CMD = -1,
	INIT_CMD = 0,
	PLANTTREE_CMD = 1,
	ADDFRUIT_CMD = 2,
	PICKFRUIT_CMD = 3,
	RATEFRUIT_CMD = 4,
	GETBESTFRUIT_CMD = 5,
	GETALLFRUITS_CMD = 6,
	UPDATE_CMD = 7,
	QUIT_CMD = 8
} commandType;

static const int numActions = 9;
static const char *commandStr[] = { "Init", "PlantTree", "AddFruit",
		"PickFruit", "RateFruit", "GetBestFruit", "GetAllFruitsByRate",
		"UpdateRottenFruits", "Quit" };

static const char* ReturnValToStr(int val) {
	switch (val) {
	case SUCCESS:
		return "SUCCESS";
	case ALLOCATION_ERROR:
		return "ALLOCATION_ERROR";
	case FAILURE:
		return "FAILURE";
	case INVALID_INPUT:
		return "INVALID_INPUT";
	default:
		return "";
	}
}

/* we assume maximum string size is not longer than 256  */
#define MAX_STRING_INPUT_SIZE (255)
#define MAX_BUFFER_SIZE       (255)

#define StrCmp(Src1,Src2) ( strncmp((Src1),(Src2),strlen(Src1)) == 0 )

typedef enum {
	error_free, error
} errorType;
static errorType parser(const char* const command);

#define ValidateRead(read_parameters,required_parameters,ErrorString) \
if ( (read_parameters)!=(required_parameters) ) { printf(ErrorString); return error; }

static bool isInit = false;

/***************************************************************************/
/* main                                                                    */
/***************************************************************************/

int main(int argc, const char**argv) {
	char buffer[MAX_STRING_INPUT_SIZE];

	// Reading commands
	while (fgets(buffer, MAX_STRING_INPUT_SIZE, stdin) != NULL) {
		fflush(stdout);
		if (parser(buffer) == error)
			break;
	};
	return 0;
}

/***************************************************************************/
/* Command Checker                                                         */
/***************************************************************************/

static commandType CheckCommand(const char* const command,
		const char** const command_arg) {
	if (command == NULL || strlen(command) == 0 || StrCmp("\n", command))
		return (NONE_CMD);
	if (StrCmp("#", command)) {
		if (strlen(command) > 1)
			printf("%s", command);
		return (COMMENT_CMD);
	};
	for (int index = 0; index < numActions; index++) {
		if (StrCmp(commandStr[index], command)) {
			*command_arg = command + strlen(commandStr[index]) + 1;
			return ((commandType) index);
		};
	};
	return (NONE_CMD);
}

/***************************************************************************/
/* Commands Functions                                                      */
/***************************************************************************/

static errorType OnInit(void** DS, const char* const command);
static errorType OnPlantTree(void* DS, const char* const command);
static errorType OnAddFruit(void* DS, const char* const command);
static errorType OnPickFruit(void* DS, const char* const command);
static errorType OnRateFruit(void* DS, const char* const command);
static errorType OnGetBestFruit(void* DS, const char* const command);
static errorType OnGetAllFruitsByRate(void* DS, const char* const command);
static errorType OnUpdateRottenFruits(void* DS, const char* const command);
static errorType OnQuit(void** DS, const char* const command);

/***************************************************************************/
/* Parser                                                                  */
/***************************************************************************/

static errorType parser(const char* const command) {
	static void *DS = NULL; /* The general data structure */
	const char* command_args = NULL;
	errorType rtn_val = error;

	commandType command_val = CheckCommand(command, &command_args);

	switch (command_val) {

	case (INIT_CMD):
		rtn_val = OnInit(&DS, command_args);
		break;
	case (PLANTTREE_CMD):
		rtn_val = OnPlantTree(DS, command_args);
		break;
	case (ADDFRUIT_CMD):
		rtn_val = OnAddFruit(DS, command_args);
		break;
	case (PICKFRUIT_CMD):
		rtn_val = OnPickFruit(DS, command_args);
		break;
	case (RATEFRUIT_CMD):
		rtn_val = OnRateFruit(DS, command_args);
		break;
	case (GETBESTFRUIT_CMD):
		rtn_val = OnGetBestFruit(DS, command_args);
		break;
	case (GETALLFRUITS_CMD):
		rtn_val = OnGetAllFruitsByRate(DS, command_args);
		break;
	case (UPDATE_CMD):
		rtn_val = OnUpdateRottenFruits(DS, command_args);
		break;
	case (QUIT_CMD):
		rtn_val = OnQuit(&DS, command_args);
		break;

	case (COMMENT_CMD):
		rtn_val = error_free;
		break;
	case (NONE_CMD):
		rtn_val = error;
		break;
	default:
		assert(false);
		break;
	};
	return (rtn_val);
}

/***************************************************************************/
/* OnInit                                                                  */
/***************************************************************************/
static errorType OnInit(void** DS, const char* const command) {
	if (isInit) {
		printf("Init was already called.\n");
		return (error_free);
	};
	isInit = true;
	int N;
	ValidateRead(sscanf(command, "%d", &N), 1, "Init failed.\n");

	*DS = Init(N);
	if (*DS == NULL) {
		printf("Init failed.\n");
		return error;
	};
	printf("Init done.\n");

	return error_free;
}

/***************************************************************************/
/* OnAddVersion                                                             */
/***************************************************************************/
static errorType OnPlantTree(void* DS, const char* const command) {
	int i,j;
	ValidateRead(sscanf(command, "%d %d", &i, &j), 2, "PlantTree failed.\n");
	StatusType res = PlantTree(DS, i, j);

	if (res != SUCCESS) {
		printf("PlantTree: %s\n", ReturnValToStr(res));
		return error_free;
	} else {
		printf("PlantTree: %s\n", ReturnValToStr(res));
	}

	return error_free;
}

/***************************************************************************/
/* OnAddApplication                                                          */
/***************************************************************************/
static errorType OnAddFruit(void* DS, const char* const command) {
	int fruitID;
	int i,j;
	int ripeRate;
	ValidateRead(
			sscanf(command, "%d %d %d %d", &i, &j, &fruitID, &ripeRate),
			4, "AddFruit failed.\n");
	StatusType res = AddFruit(DS, i,j, fruitID, ripeRate);

	if (res != SUCCESS) {
		printf("AddFruit: %s\n", ReturnValToStr(res));
		return error_free;
	}

	printf("AddFruit: %s\n", ReturnValToStr(res));
	return error_free;
}

/***************************************************************************/
/* OnRemoveApplication                                                            */
/***************************************************************************/
static errorType OnPickFruit(void* DS, const char* const command) {
	int fruitID;
	ValidateRead(sscanf(command, "%d", &fruitID), 1,
			"PickFruit failed.\n");
	StatusType res = PickFruit(DS, fruitID);

	if (res != SUCCESS) {
		printf("PickFruit: %s\n", ReturnValToStr(res));
		return error_free;
	}

	printf("PickFruit: %s\n", ReturnValToStr(res));
	return error_free;
}

/***************************************************************************/
/* OnIncreaseDownloads                                                         */
/***************************************************************************/
static errorType OnRateFruit(void* DS, const char* const command) {
	int fruitID;
	int ripeRate;
	ValidateRead(sscanf(command, "%d %d", &fruitID, &ripeRate), 2,
			"RateFruit failed.\n");
	StatusType res = RateFruit(DS, fruitID, ripeRate);

	if (res != SUCCESS) {
		printf("RateFruit: %s\n", ReturnValToStr(res));
		return error_free;
	}

	printf("RateFruit: %s\n", ReturnValToStr(res));
	return error_free;
}

/***************************************************************************/
/* OnGetBestFruit                                                         */
/***************************************************************************/
static errorType OnGetBestFruit(void* DS, const char* const command) {
	int i, j;
	ValidateRead(sscanf(command, "%d %d", &i, &j), 2, "GetBestFruit failed.\n");
	int fruitID;
	StatusType res = GetBestFruit(DS, i,j, &fruitID);

	if (res != SUCCESS) {
		printf("GetBestFruit: %s\n", ReturnValToStr(res));
		return error_free;
	}

	cout << "Best fruit is: " << fruitID << endl;
	return error_free;
}

/***************************************************************************/
/* OnGetAllFruits                                                        */
/***************************************************************************/

void PrintAll(int *fruits, int numOfFruits) {
	if (numOfFruits > 0) {
		cout << "Rank	||	Fruit" << endl;
	}

	for (int i = 0; i < numOfFruits; i++) {
		cout << i + 1 << "\t||\t" << fruits[i] << endl;
	}
	cout << "and that's all!" << endl;

	free(fruits);
}

static errorType OnGetAllFruitsByRate(void* DS, const char* const command) {
	int i, j;
	ValidateRead(sscanf(command, "%d %d", &i, &j), 2,
			"GetAllFruitsByRate failed.\n");
	int* fruits;
	int numOfFruits;
	StatusType res = GetAllFruitsByRate(DS, i,j, &fruits, &numOfFruits);

	if (res != SUCCESS) {
		printf("GetAllFruitsByRate: %s\n", ReturnValToStr(res));
		return error_free;
	}

	PrintAll(fruits, numOfFruits);
	return error_free;
}

/***************************************************************************/
/* OnUpdateDownloads                                                           */
/***************************************************************************/
static errorType OnUpdateRottenFruits(void* DS, const char* const command) {
	int rottenBase;
	int rottenFactor;
	ValidateRead(sscanf(command, "%d %d", &rottenBase, &rottenFactor), 2,
			"UpdateRottenFruits failed.\n");
	StatusType res = UpdateRottenFruits(DS, rottenBase, rottenFactor);

	if (res != SUCCESS) {
		printf("UpdateRottenFruits: %s\n", ReturnValToStr(res));
		return error_free;
	}

	printf("UpdateRottenFruits: %s\n", ReturnValToStr(res));
	return error_free;
}

/***************************************************************************/
/* OnQuit                                                                  */
/***************************************************************************/
static errorType OnQuit(void** DS, const char* const command) {
	Quit(DS);
	if (*DS != NULL) {
		printf("Quit failed.\n");
		return error;
	};

	isInit = false;
	printf("Quit done.\n");

	return error_free;
}

#ifdef __cplusplus
}
#endif

