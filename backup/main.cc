#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

struct display
{ 
	static constexpr int row {20};    // across      (X coord) k 
  static constexpr int column {10}; // up and down (Y coord) i
    
	std::string displayArray[column][row] = 
	{
		{"1","0","0","0","0","0","0","1","0","0","0","1","0","0","0","0","0","0","0","1"},	// top left 0,0
		{"1","1","1","1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},	
		{"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},	
		{"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},	
		{"1","0","0","0","0","0","0","0","1","1","1","0","0","0","0","0","0","0","0","1"},	
		{"1","0","0","0","0","0","0","0","1","1","1","0","0","0","0","0","0","0","0","1"},	
		{"1","0","0","0","0","0","0","0","1","1","1","0","0","0","0","0","0","0","0","1"},	
		{"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},	
		{"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","1"},	
		{"1","0","0","0","0","0","1","0","0","0","0","1","0","0","0","0","0","0","0","1"},	// bottom right 9,19
	};

  void deadCellAlgorithm(int columnY, int columnX)
  {
  	std::ostringstream stringStream;
  					  
  	std::string tempNeighbourTop         { displayArray[columnY - 1][columnX] };
  	std::string tempNeighbourBottom      { displayArray[columnY + 1][columnX] };
  						
  	std::string tempNeighbourLeft        { displayArray[columnY][columnX - 1] };
  	std::string tempNeighbourRight       { displayArray[columnY][columnX + 1] };
  						
  	std::string tempNeighbourTopLeft     { displayArray[columnY - 1][columnX - 1] };
  	std::string tempNeighbourTopRight    { displayArray[columnY - 1][columnX + 1] };
  						
  	std::string tempNeighbourBottomLeft  { displayArray[columnY + 1][columnX - 1] };
  	std::string tempNeighbourBottomRight { displayArray[columnY + 1][columnX + 1] };
  	
  	stringStream << tempNeighbourTop << tempNeighbourBottom << tempNeighbourLeft << tempNeighbourRight
  							 << tempNeighbourTopLeft << tempNeighbourTopRight << tempNeighbourBottomLeft << tempNeighbourBottomRight;
  	
  	std::string combinator { stringStream.str() };
  	std::cout << "combinator result: " << combinator << '\n';
  	
  	int counter {0};
  	          
  	for(int i {0}; i < 8; ++i)
  	{ 
  						  
  	  if( combinator[i] == 'x' ) { ++counter; }
  		std::cout << i <<": " << combinator[i] << '\n' << "counter: " << counter << '\n'; 
  	}
  	std::cout << "counter outside for loop: " << counter <<'\n';
  	
  	if(counter == 3) { displayArray[columnY][columnX] = "1"; }
  	else{ displayArray[columnY][columnX] = "x"; }
  }
  
	void cellAlgorithm(int columnY, int columnX)
	{
		/* rule set
		
    Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    */

    // Any live cell with two or three live neighbours lives on to the next generation.
    // Any live cell with more than three live neighbours dies, as if by overpopulation.
		// Any live cell with fewer than two live neighbours dies, as if by underpopulation.
		// if no neighbours what so ever, then cell dies
		if(	( displayArray[columnY][columnX - 1] != "1") && ( displayArray[columnY][columnX + 1] != "1") &&
			  ( displayArray[columnY - 1][columnX] != "1") && ( displayArray[columnY - 1][columnX - 1] != "1") && ( displayArray[columnY - 1][columnX + 1] != "1") &&
				( displayArray[columnY + 1][columnX] != "1") && ( displayArray[columnY + 1][columnX - 1] != "1") && ( displayArray[columnY + 1][columnX + 1] != "1")   )
				{
					displayArray[columnY][columnX] = "x";
				}else
				{
				  std::ostringstream stringStream;
				  
					std::string tempNeighbourTop         { displayArray[columnY - 1][columnX] };
					std::string tempNeighbourBottom      { displayArray[columnY + 1][columnX] };
					
					std::string tempNeighbourLeft        { displayArray[columnY][columnX - 1] };
					std::string tempNeighbourRight       { displayArray[columnY][columnX + 1] };
					
					std::string tempNeighbourTopLeft     { displayArray[columnY - 1][columnX - 1] };
					std::string tempNeighbourTopRight    { displayArray[columnY - 1][columnX + 1] };
					
					std::string tempNeighbourBottomLeft  { displayArray[columnY + 1][columnX - 1] };
					std::string tempNeighbourBottomRight { displayArray[columnY + 1][columnX + 1] };

					stringStream << tempNeighbourTop << tempNeighbourBottom << tempNeighbourLeft << tempNeighbourRight
											 << tempNeighbourTopLeft << tempNeighbourTopRight << tempNeighbourBottomLeft << tempNeighbourBottomRight;

					std::string combinator { stringStream.str() };
					std::cout << "combinator result: " << combinator << '\n';

          int counter {0};
          
					for(int i {0}; i < 8; ++i)
					{ 
					  
						if( combinator[i] == '1' ) { ++counter; }
						std::cout << i <<": " << combinator[i] << '\n' << "counter: " << counter << '\n'; 
					}
					std::cout << "counter outside for loop: " << counter <<'\n';

					if(counter < 2) { displayArray[columnY][columnX] = "x"; }
					else if(counter > 3) { displayArray[columnY][columnX] = "x"; }
					else if(counter == 2 || counter == 3) { displayArray[columnY][columnX] = "1"; }

					
				}
				
				//else count how many there are.
    
	} 
  
	void edgeDetection(int columnY, int columnX)
	{
	  // creating edge detection, redo if statement to have a border around outside of array.
	  // for loop for traversing the sections perhaps.
	  if ( ( columnY == 0 || columnY == 1 || columnY == 2 || columnY == 3 ||
	         columnY == 4 || columnY == 5 || columnY == 6 || columnY == 7 ||
	         columnY == 8 || columnY == 9 ) && ( columnX == 0 || columnX == 19 ) ) 
	  {
	   // std::cout << columnY << " " << columnX << '\n';
	   //std::cout << "on boundary" << '\n'; 
	   displayArray[columnY][columnX] = "0";
	  }else if( ( columnX == 1  || columnX == 2  || columnX == 3  ||
	  	          columnX == 4  || columnX == 5  || columnX == 6  || columnX == 7  ||
	  	          columnX == 8  || columnX == 9  || columnX == 10 || columnX == 11 ||
	  	          columnX == 12 || columnX == 13 || columnX == 14 || columnX == 15 ||
	  	          columnX == 16 || columnX == 17 || columnX == 18) && ( columnY == 0 || columnY == 9 ) ) 
	  {
	  	  	//std::cout << "on boundary" << '\n'; 
	  	  	displayArray[columnY][columnX] = "0";
	  }else
	  { 
	  	cellAlgorithm(columnY, columnX); 
	  } 

    
	  
	}

	void updateDisplay()
	{
	  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		for(int i {0}; i < column; ++i)
		{
			for(int k {0}; k < row; ++k)
		  {
		  	std::cout << displayArray[i][k] << " ";
		  	  	
		  }
	  	std::cout << '\n';
		}
		std::this_thread::sleep_for(std::chrono::milliseconds{1000}); // framerate
	}

  void searchArray()
  {
    //std::cout << column << '\n';
    //std::cout << row << '\n';
    
  	for(int i {0}; i < column; ++i)
  	{
  	  for(int k {0}; k < row; ++k)
  	  {
  	    // if(displayArray[i][k] == "1") { std::printf("value of i: %d , value of k: %d", i, k); }
  	    if(displayArray[i][k] == "1") { edgeDetection(i,k); }
  	    if(displayArray[i][k] == "x") { deadCellAlgorithm(i,k); }
  	  }
  	}

  	
  }

  
}init;

int main()
{
	for(int i {0}; i < 5; ++i)
	{
		init.updateDisplay();
  	init.searchArray();
	}

  
	return 0;
}
