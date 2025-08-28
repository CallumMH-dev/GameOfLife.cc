#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include <random>

/* rule set
*
*	 Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*  Any live cell with two or three live neighbours lives on to the next generation.
*  Any live cell with more than three live neighbours dies, as if by overpopulation.
*	 Any live cell with fewer than two live neighbours dies, as if by underpopulation.
*
*/
	 

struct display
{ 
  std::string r()
  {
    std::string x {};
    
    std::random_device seed;
    
    std::mt19937 generator(seed());
    std::uniform_int_distribution<int> dist(1,9);

    int randomNumber { dist(generator) };

    if(randomNumber == 1) { x = "."; }
    else if(randomNumber == 2 || randomNumber == 3 || randomNumber == 4 || randomNumber == 5 ||
            randomNumber == 6 || randomNumber == 7 || randomNumber == 8 || randomNumber == 9) { x = " "; }
    
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
  	
  	 int counter {0};
  	          
  	 for(int i {0}; i < 8; ++i)
  	 {   					  
  	   if( combinator[i] == '.' ) { ++counter; } 
  	 }
  	   	
  	 if(counter == 3) { displayArray[columnY][columnX] = "."; }
  	 else{ displayArray[columnY][columnX] = " "; }
  }
  
	void cellAlgorithm(int columnY, int columnX)
	{
	  		
		 std::ostringstream stringStream;
		 
		 std::string tempNeighbourTop          { displayArray[columnY - 1][columnX] };
		 std::string tempNeighbourBottom       { displayArray[columnY + 1][columnX] };

     std::string tempNeighbourLeft        { displayArray[columnY][columnX - 1] };
		 std::string tempNeighbourRight       { displayArray[columnY][columnX + 1] };
			
		 std::string tempNeighbourTopLeft     { displayArray[columnY - 1][columnX - 1] };
		 std::string tempNeighbourTopRight    { displayArray[columnY - 1][columnX + 1] };
			
		 std::string tempNeighbourBottomLeft  { displayArray[columnY + 1][columnX - 1] };
		 std::string tempNeighbourBottomRight { displayArray[columnY + 1][columnX + 1] };

     stringStream << tempNeighbourTop << tempNeighbourBottom << tempNeighbourLeft << tempNeighbourRight
                  << tempNeighbourTopLeft << tempNeighbourTopRight << tempNeighbourBottomLeft << tempNeighbourBottomRight;
         
		 std::string combinator { stringStream.str() };
			         
     int counter {0};
          
		 for(int i {0}; i < 8; ++i)
		 { 
       if( combinator[i] == '.' ) { ++counter; }
     }
			          
  	 if(counter < 2) { displayArray[columnY][columnX] = " "; }
		 else if(counter > 3) { displayArray[columnY][columnX] = " "; }
		 else if(counter == 2 ||counter == 3) { displayArray[columnY][columnX] = "."; }

	} 

	void updateDisplay()
	{
	  std::cout << "\033[2J";
		for(int i {0}; i < column; ++i)
		{ 
		  std::cout << '\n';
			for(int k {0}; k < row; ++k)
		  {
		  	std::cout << displayArray[i][k] << " ";
		  	  	
		  }
	  	std::cout << '\n';
		}
		std::this_thread::sleep_for(std::chrono::milliseconds{63}); // framerate
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
  	    if(displayArray[i][k] == ".") { cellAlgorithm(i, k);  }
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
