/****************************************************************************/
/*                                                                          */
/* This file contains the interface functions                               */
/* you should use for the wet ex 1                                          */ 
/*                                                                          */ 
/****************************************************************************/

/****************************************************************************/
/*                                                                          */ 
/* File Name : library1.h                                                   */ 
/*                                                                          */ 
/****************************************************************************/

#ifndef _234218_WET1_
#define _234218_WET1_

#ifdef __cplusplus
extern "C" {
#endif

/* Return Values
 * ----------------------------------- */
typedef enum {
    SUCCESS = 0,
    FAILURE = -1,
    ALLOCATION_ERROR = -2,
    INVALID_INPUT = -3
} StatusType;

/* Required Interface for the Data Structure
 * -----------------------------------------*/

/* Description:   Initiates the data structure.
 * Input:         DS - A pointer to the data structure.
 * 				  N - size of field
 * Output:        None.
 * Return Values: A pointer to a new instance of the data structure - as a void* pointer.
 */
void* Init(int N);

/* Description:   Plants a tree in the (i,j) location inside the field.
 * Input:         DS - A pointer to the data structure.
 *                i - The row to plant the tree in.
 *                j - The spot to plant the tree inside the row.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if i,j are not in [0,N-1]
 *                FAILURE - If a tree already exists in the spot
 *                SUCCESS - Otherwise.
 */
StatusType PlantTree(void *DS, int i, int j);

/* Description:   Adds a fruit to (i,j)'th tree.
 * Input:         DS - A pointer to the data structure.
 *                i - The tree's row
 *                j - The tree's spot inside the row
 *                fruitID - the unique fruit's ID.
 *                ripeRate - the ripeness level of the fruit.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if i,j are not in [0,N-1]
 *                				or if fruitID<=0, or if ripeRate<=0
 *                FAILURE -	If fruitID is already used, or the (i,j)'th tree doesn't exist
 *                SUCCESS - Otherwise.
 */
StatusType AddFruit(void *DS, int i, int j, int fruitID, int ripeRate);


/* Description:   Removes a fruit from the tree
 * Input:         DS - A pointer to the data structure.
 *                fruitID - the unique fruit's ID.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if fruitID<=0
 *                FAILURE -	If fruitID doesn't exist
 *                SUCCESS - Otherwise.
 */
StatusType PickFruit(void *DS, int fruitID);

/* Description:   Updated a fruit's ripeness
 * Input:         DS - A pointer to the data structure.
 *                fruitID - the unique fruit's ID.
 *                ripeRate - the ripeness level of the fruit.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if fruitID<=0, or if ripeRate<=0
 *                FAILURE -	If fruitID doesn't exist
 *                SUCCESS - Otherwise.
 */
StatusType RateFruit(void *DS, int fruitID, int ripeRate);

/* Description:   Returns the best fruit in the (i,j)'th tree, by ripeness
 * Input:         DS - A pointer to the data structure.
 *                i - The tree's row
 *                j - The tree's spot inside the row
 * Output:        fruitID - A pointer to a variable that should be updated to the ID of the best fruit,
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if fruitID == NULL or if i,j are not in [0,N-1]
 *                FAILURE - If the (i,j)'th tree doesn't exist
 *                SUCCESS - Otherwise.
 */
StatusType GetBestFruit(void *DS, int i, int j, int *fruitID);

/* Description:   Returns all the fruits in the (i,j)'th tree sorted by their rate.
 * Input:         DS - A pointer to the data structure.
 *                i - The tree's row
 *                j - The tree's spot inside the row
 * Output:        fruits - A pointer to a to an array that you should update with the fruits' IDs sorted by their rates,
 *			in case two fruits have the same download count they should be sorted by their ID.
 *                numOfFruits - A pointer to a variable that should be updated to the number of fruits.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If any of the arguments is NULL or if i,j are not in [0,N-1]
 *                FAILURE - If the (i,j)'th tree doesn't exist
 *                SUCCESS - Otherwise.
 */
StatusType GetAllFruitsByRate(void *DS, int i, int j, int **fruits, int *numOfFruits);

/* Description:   Updates the ripeness of the fruits where fruitID % rottenBase == 0.
 * 				  For each matching fruit, multiplies its ripeness level by multiplyFactor.
 * Input:         DS - A pointer to the data structure.
 *                rottenBase - The base for the modulo.
 *		  		  rottenFactor - The multiply factor.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if rottenBase < 1 or if rottenFactor < 1
 *                SUCCESS - Otherwise.
 */
StatusType UpdateRottenFruits(void *DS, int rottenBase, int rottenFactor);


/* Description:   Quits and deletes the database.
 *                DS should be set to NULL.
 * Input:         DS - A pointer to the data structure.
 * Output:        None.
 * Return Values: None.
 */
void Quit(void** DS);

#ifdef __cplusplus
}
#endif

#endif    /*_234218_WET1_ */ 

