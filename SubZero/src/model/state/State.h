#ifndef STATE_H_
#define STATE_H_
#include "../../Observable.h"
#include "../../util/data/Data.h"

#include <string>
#include <list>
#include <vector>


class State: public Observable {

protected:
	//boolean to signal if a new frame has started
	bool frameStarted;

	//boolean to signal if the state is currently in use
	bool inUse;

	//the length of the linked list
	//The amount of frames that the state will hold
	int maxLength;

	//LinkedList <Vector<Data>>
	//std::list<std::vector<Data*>> stateData;

	//Initialize the class
	void init();

	/**
	 * Returns a deep copy of an State specified with the _ID_ at _i_ frames before this call
	 * @param ID = id of the State that is needed
	 * @param i = how many frames ago was the State stored (zero indexed; newest frame = 0)
	 * @return returns the pointer to a deep copied State
	 */
	virtual Data* getState (std::string ID, int i) = 0;

	/**
	 * Returns a deep copy of the latest State specified with the _ID_
	 * (same as calling getState(ID, 0))
	 * @param ID = id of the State that is needed
	 * @return returns the pointer to a deep copied State
	 */
	virtual Data* getState (std::string ID) = 0;

	/**
	 * Sets the state
	 * SHOULD ONLY BE CALLED AFTER startFrame() IS CALLED
	 * @param d = Pointer to state data to be set for this frame
	 * @return an int indicating whether the operation was successful
	 *  	- 0 = successful
	 *  	- 1 = called this function before startFrame is called
	 */
	//int setState(Data* d);

	/**
	 * Same thing as setState, except it takes an entire vector of data instead of 1 data
	 * Sets the state
	 * SHOULD ONLY BE CALLED AFTER startFrame() IS CALLED
	 * @param d = vector of State data to be set for this frame
	 * @return an int indicating whether the operation was successful
	 *  	- 0 = successful
	 *  	- 1 = called this function before startFrame is called
	 */
	//virtual int setState(std::vector<Data*> d) = 0;

	/**
	 * Gets a pointer to a deep copy of the newest raw State
	 * @return data = pointer to the deep copy of the raw State
	 */
	virtual Data* getRaw() = 0;

	/**
	 * Gets a pointer to the deep copy of the raw State _i_ frames before
	 * @param i = how many frames ago the raw State was recorded (zero indexed; newest frame = 0)
	 * @return a pointer to the deep copy of the raw State data _i_ frames before this function call
	 */
	virtual Data* getRaw(int i) = 0;

public:
	State();	//constructor
	State(int framesStored);

	virtual ~State();	//deconstructor

	/**
	 * Starts a new Frame
	 * Have to be called before you can call setState()
	 * Only Model should be calling this function (might implement a check for that)
	 */
	//void startFrame();

	/**
	 * Ends the frame
	 * Have to be called after startFrame() is called
	 * If called before startFrame, then it does nothing
	 * Be careful when calling this, since you cannot change the frame after it has ended
	 */
	//void endFrame();

};
#endif /* SRC_MODEL_STATE_STATE_H_ */
