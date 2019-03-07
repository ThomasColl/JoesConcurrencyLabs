/*! \fn Barrier.cpp
    \brief Barrier header file for defining method signatures
    \author Thomas Coll
    Creation Date: 14/02/19
    License: Creative Commons


*/
/* Barrier.h --- Barrier.h
 * 
 * Filename: Barrier.h
 * Description: 
 * Author: Joseph
 * Maintainer: 
 * Created: Tue Jan  8 12:12:03 2019 (+0000)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: Tue Jan  8 12:15:54 2019 (+0000)
 *           By: Joseph
 *     Update #: 2
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change Log:
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */
#include <mutex>
#include <condition_variable>
#include <chrono>
#include "Semaphore.h"

/*! Class Definition*/
#pragma once
class Barrier{
	/*! Private Variables*/
	private:
		unsigned int count = 0; /*!< Holds the Semaphore count */
	    	std::shared_ptr<Semaphore> sem1;
		std::shared_ptr<Semaphore> sem2;
		std::shared_ptr<Semaphore> mutex;
	    	int numThreads; /* Will hold a negative version of the number of threads */

	/*! Public Method Signatures*/
 	public:
		Barrier(int numThreads);
		void Wait(); 
  		~Barrier();
};


/* Barrier.h ends here */
