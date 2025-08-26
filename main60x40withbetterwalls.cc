#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include <random>

struct display
{ 
  std::string r()
  {
    std::string x {};
    
    std::random_device seed;
    
    std::mt19937 generator(seed());
    std::uniform_int_distribution<int> dist(1,2);

    int randomNumber { dist(generator) };

    if(randomNumber == 1) { x = "."; }
    else if(randomNumber == 2) { x = " "; }
    
  	return x;
  }

	static constexpr int row {60};    // across      (X coord) k 
  static constexpr int column {30}; // up and down (Y coord) i
    
	std::string displayArray[column][row] = 
	{
		{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#",r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),r(),"#"},
		{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
	  
	  
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
  	//std::cout << "combinator result: " << combinator << '\n';
  	
  	int counter {0};
  	          
  	for(int i {0}; i < 8; ++i)
  	{ 
  						  
  	  if( combinator[i] == '.' ) { ++counter; }
  		//std::cout << i <<": " << combinator[i] << '\n' << "counter: " << counter << '\n'; 
  	}
  	//std::cout << "counter outside for loop: " << counter <<'\n';
  	
  	if(counter == 3) { displayArray[columnY][columnX] = "."; }
  	else{ displayArray[columnY][columnX] = " "; }
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
					//std::cout << "combinator result: " << combinator << '\n';

          int counter {0};
          
					for(int i {0}; i < 8; ++i)
					{ 
					  
						if( combinator[i] == '.' ) { ++counter; }
						//std::cout << i <<": " << combinator[i] << '\n' << "counter: " << counter << '\n'; 
					}
					//std::cout << "counter outside for loop: " << counter <<'\n';
          
					if(counter < 2) { displayArray[columnY][columnX] = " "; }
					else if(counter > 3) { displayArray[columnY][columnX] = " "; }
					else if(counter == 3) { displayArray[columnY][columnX] = "."; }

					
	
				
				//else count how many there are.
    
	} 
  
	void edgeDetection(int columnY, int columnX)
	{
	  // creating edge detection, redo if statement to have a border around outside of array.
	  // for loop for traversing the sections perhaps.
	  if ( ( columnY == 0  || columnY == 1  || columnY == 2  || columnY == 3  ||
	         columnY == 4  || columnY == 5  || columnY == 6  || columnY == 7  ||
	         columnY == 8  || columnY == 9  || columnY ==10  || columnY ==11  ||
	         columnY == 12 || columnY == 13 || columnY == 14 || columnY == 15 ||
	         columnY == 16 || columnY == 17 || columnY == 18 || columnY == 19 ||
	         columnY == 20 || columnY == 21 || columnY == 22 || columnY == 23 ||
	         columnY == 24 || columnY == 25 || columnY == 26 || columnY == 27 ||
	         columnY == 28 || columnY == 29 ) && ( columnX == 0 || columnX == 59 ) ) 
	  {
	   // std::cout << columnY << " " << columnX << '\n';
	   //std::cout << "on boundary" << '\n'; 
	   displayArray[columnY][columnX] = "0";
	  }else if( ( columnX == 0  || columnX == 1  || columnX == 2  || columnX == 3  ||
	  	          columnX == 4  || columnX == 5  || columnX == 6  || columnX == 7  ||
	  	          columnX == 8  || columnX == 9  || columnX == 10 || columnX == 11 ||
	  	          columnX == 12 || columnX == 13 || columnX == 14 || columnX == 15 ||
	  	          
	  	          columnX == 16 || columnX == 17 || columnX == 18 || columnX == 19 ||
	  	          columnX == 20 || columnX == 21 || columnX == 22 || columnX == 23 ||
	  	          columnX == 24 || columnX == 25 || columnX == 26 || columnX == 27 ||
	  	          
	  	          columnX == 28 || columnX == 29 || columnX == 30 || columnX == 31 ||
	  	          columnX == 32 || columnX == 33 || columnX == 34 || columnX == 35 ||
	  	          columnX == 36 || columnX == 37 || columnX == 38 || columnX == 39 ||
	  	          
	  	          columnX == 40 || columnX == 41 || columnX == 42 || columnX == 43 ||
	  	          columnX == 44 || columnX == 45 || columnX == 46 || columnX == 47 ||
	  	          columnX == 48 || columnX == 49 || columnX == 50 || columnX == 51 ||
	  	          columnX == 52 || columnX == 53 || columnX == 54 || columnX == 55 ||
	  	          columnX == 56 || columnX == 57 || columnX == 58 || columnX == 59 ) && ( columnY == 0 || columnY == 29 ) ) 
	  {
	  	//std::cout << "on boundary" << '\n'; 
	  	displayArray[columnY][columnX] = "#";
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
		  std::cout << '\n';
			for(int k {0}; k < row; ++k)
		  {
		  	std::cout << displayArray[i][k] << " ";
		  	  	
		  }
	  	std::cout << '\n';
		}
		std::this_thread::sleep_for(std::chrono::milliseconds{50}); // framerate
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
  	    if(displayArray[i][k] == ".") { edgeDetection(i,k); }
  	    if(displayArray[i][k] == " ") { deadCellAlgorithm(i,k); }
  	  }
  	}

  	
  }

  
}init;

int main()
{
	for(;;)
	{
		init.updateDisplay();
  	init.searchArray();
	}

  
	return 0;
}
