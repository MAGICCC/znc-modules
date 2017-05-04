/* Copyright 2016 Chris Tyrrel & edited by MAGIC (Peter Stanke)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <znc/Modules.h>
#include <znc/znc.h>
#include <znc/Chan.h>
#include <znc/IRCNetwork.h>

class CRegisteredChanMod : public CModule {
    public:

    MODCONSTRUCTOR(CRegisteredChanMod) {}

    void OnRawMode(const CNick& OpNick, CChan& Channel, const CString& sModes, const CString& sArgs) override {
        CIRCNetwork* pNetwork = Channel.GetNetwork();
        if (sModes.Contains("-z")) {
            pNetwork->PutIRC("PART " + Channel.GetName());
            DEBUG("Channel successfully parted.");
            /*if (pNetwork->DelChan(Channel.GetName())) {
               PutModule(Channel.GetName() + " removed due to removal of registration mode."); 
            } else {
               PutModule(Channel.GetName() + " could not be removed.");                 
            }*/
        }
    }
};

NETWORKMODULEDEFS(CRegisteredChanMod, "Parts a channel that has become unregistered.")