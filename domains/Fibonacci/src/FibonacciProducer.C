/*
 * Copyright (C) by
 *   MetraLabs GmbH (MLAB), GERMANY
 * and
 *   Neuroinformatics and Cognitive Robotics Labs (NICR) at TU Ilmenau, GERMANY
 * All rights reserved.
 *
 * Contact: info@mira-project.org
 *
 * Commercial Usage:
 *   Licensees holding valid commercial licenses may use this file in
 *   accordance with the commercial license agreement provided with the
 *   software or, alternatively, in accordance with the terms contained in
 *   a written agreement between you and MLAB or NICR.
 *
 * GNU General Public License Usage:
 *   Alternatively, this file may be used under the terms of the GNU
 *   General Public License version 3.0 as published by the Free Software
 *   Foundation and appearing in the file LICENSE.GPL3 included in the
 *   packaging of this file. Please review the following information to
 *   ensure the GNU General Public License version 3.0 requirements will be
 *   met: http://www.gnu.org/copyleft/gpl.html.
 *   Alternatively you may (at your option) use any later version of the GNU
 *   General Public License if such license has been publicly approved by
 *   MLAB and NICR (or its successors, if any).
 *
 * IN NO EVENT SHALL "MLAB" OR "NICR" BE LIABLE TO ANY PARTY FOR DIRECT,
 * INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT OF
 * THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF "MLAB" OR
 * "NICR" HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * "MLAB" AND "NICR" SPECIFICALLY DISCLAIM ANY WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND "MLAB" AND "NICR" HAVE NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS OR MODIFICATIONS.
 */

/**
 * @file FibonacciProducer.C
 *    writing floating fibonacci numbers into the channel
 *
 * @author Venkata
 * @date   2024/04/11
 */
#include <fw/Unit.h>

using namespace mira;

namespace sequence { 


/**
 * writing floating fibonacci numbers into a channel
 */
class FibonacciProducer : public Unit
{
MIRA_OBJECT(FibonacciProducer)

public:

	FibonacciProducer();

	template<typename Reflector>
	void reflect(Reflector& r)
	{
		MIRA_REFLECT_BASE(r, Unit);
	}

protected:

	virtual void initialize();

	virtual void process(const Timer& timer);

private:
	Channel<int> mIntChannel;  //declaring channel and variables.

	int mValue;
	int a,b,n;
};

FibonacciProducer::FibonacciProducer() : Unit(Duration::milliseconds(100))
{
}

void FibonacciProducer::initialize()
{
	mIntChannel = publish<int>("FibonacciChannel");  //initialize first two digits
	a = 0;   
	b = 1;
	mValue=0;
}

void FibonacciProducer::process(const Timer& timer)
{
	std::cout << "Please enter How many numbers of Fibonacci Sequence is needed " << std::endl;
	std::cin >> n ; 
	std::cout << "Fibonacci Sequence are of " << n << " numbers required"  << std::endl;
	
	//logic for Calculation of Fibonacci Sequence
	for (int i=0; i <= n; i++)
	{
		mIntChannel.post(mValue);
		std::cout << i+1 << "). Fibonacci Sequence Number : " << mValue << std::endl;
		a = b;
		b = mValue;
		mValue = a + b;  //addition and updating the values
	}
	std::cout << "Fibonacci Sequence is Completed. "  << std::endl;
}
}

MIRA_CLASS_SERIALIZATION(sequence::FibonacciProducer, mira::Unit);
