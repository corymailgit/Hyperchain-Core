/*Copyright 2016-2018 hyperchain.net (Hyperchain)

Distributed under the MIT software license, see the accompanying
file COPYING or https://opensource.org/licenses/MIT.

Permission is hereby granted, free of charge, to any person obtaining a copy of this 
software and associated documentation files (the "Software"), to deal in the Software
without restriction, including without limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include "UInt128.h"
#include "CNode.h"

#include <mutex>
using namespace std;

class NodeManager {

public: 
	
	NodeManager() {}
	NodeManager(const NodeManager &) = delete;
	NodeManager & operator=(const NodeManager &) = delete;

	~NodeManager() {}
	void myself(const CNode &me);
	CNode & myself();
	CNode * searchBuddy();
	CNode * getNode(const CUInt128 &nodeid);
    
	void addNode(CNode && node);
	void updateNode(CNode && node);

	int sendTo(const CNode &targetNode, string & msgbuf);
	int sendTo(const CUInt128 &targetNodeid, string & msgbuf);

	const CNodeList * getNodeList();
	void loadMyself();
	void saveMyself();
	void loadNeighbourNodes();
	void saveNeighbourNodes();


private: 

    CNode _me;
    CNodeList _nodelist;
	mutex _guard;
};