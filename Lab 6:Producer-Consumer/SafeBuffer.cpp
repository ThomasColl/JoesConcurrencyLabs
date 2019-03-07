/* SafeBuffer.cpp --- 
 * 
 * Filename: SafeBuffer.cpp
 * Description: 
 * Author: Thomas
 * Created: Fri Mar  1 12:30:23 2019 (+0000)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: Tue Jan  8 12:30:25 2019 (+0000)
 *           By: Joseph
 *     Update #: 1
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

#include "SafeBuffer.h"

SafeBuffer::SafeBuffer() {
	theMutex = std::shared_ptr<Semaphore>(new Semaphore(1));
	theSemaphore = std::make_shared<Semaphore>(0);
}

int SafeBuffer::push(Event e) {
	theMutex->Wait();
	theData.push_back(e);
	int size = theData.size();
	theMutex->Signal();
	theSemaphore->Signal();
	return size;
}

Event SafeBuffer::pop() {
	theSemaphore->Wait();
	theMutex->Wait();
	Event e = theData.back();
	theData.pop_back();
	theMutex->Signal();
	return e;
}

/* SafeBuffer.h ends here */
