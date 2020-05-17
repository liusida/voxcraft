/*******************************************************************************
Copyright (c) 2010, Jonathan Hiller
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are
met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
    * The name if its contributors may not be used to endorse or promote products derived from this software without specific prior written
permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#include "VoxCad.h"

int main(int argc, char *argv[]) {
    printf("Loading...");
    QApplication a(argc, argv);
    VoxCad w;
    bool openHistory = false;
    if (argc > 1) {
        QString Path = argv[1];
        if (Path.right(8) == ".history") {
            openHistory = true;
			QString windowName = QFileInfo(Path).baseName();
            w.MainSim.LoadHistoryFile(Path);
            w.PhysicsMode(true);
            w.MainSim.pSimView->SetCurViewVox(RVV_HISTORY);
            w.MainSim.LockCoMToCenter = true;
			w.SetWindowName(windowName);
        } else if (Path.right(3) == "vxc")
            w.MainObj.LoadVXCFile(Path.toStdString()); // open a file if we've passed the args...
        else if (Path.right(3) == "vxp")
            w.MainObj.LoadVXPFile(Path.toStdString()); // open a file if we've passed the args...
        else if (Path.right(3) == "vxa")
            w.MainSim.LoadVXAFile(Path.toStdString()); // open a file if we've passed the args...
    }
    w.show();
    if (openHistory)
        w.ViewPhysicsWindow(true);
    return a.exec();
}
