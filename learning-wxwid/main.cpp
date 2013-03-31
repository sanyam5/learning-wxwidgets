#include "wx/wx.h"

class MyApp: public wxApp
{
    virtual bool OnInit();
};


class MyFrame: public wxFrame
{
public:

    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void ButtonA(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};


enum
{
    ID_Quit = 1,
    ID_About,
    BUTTON_Hello,
};

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Quit,  MyFrame::OnQuit)
    EVT_MENU(ID_About, MyFrame::OnAbout)
    EVT_MENU(BUTTON_Hello, MyFrame::ButtonA)

END_EVENT_TABLE()


IMPLEMENT_APP(MyApp)


bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( _("Hello World"), wxPoint(50, 50), wxSize(450, 340) );
    frame->Show(true);
    SetTopWindow(frame);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
       : wxFrame(NULL, -1, title, pos, size)
{
     wxButton *   mybutton[26];


    mybutton[0] = new wxButton(this, BUTTON_Hello+0, _T("A"),   // shows a button on this window
      wxDefaultPosition, wxDefaultSize, 0);

    wxMenu *menuFile = new wxMenu;

    menuFile->Append( ID_About, _("&About...") );
    menuFile->AppendSeparator();
    menuFile->Append( ID_Quit, _("E&xit") );

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, _("&File") );

    SetMenuBar( menuBar );

    CreateStatusBar();
    SetStatusText( _("Welcome to wxWidgets!") );
}


void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}





void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox( _("This is a wxWidgets Hello world sample"),
                  _("About Hello World"),
                  wxOK | wxICON_INFORMATION, this );
}


void MyFrame::ButtonA(wxCommandEvent& WXUNUSED(event))
{

    printf("Arrey Bhai Printing\n");
    wxMessageBox( _("Lol max!!"),
                  _("About Hello jgh"),
                  wxOK | wxICON_INFORMATION, this );
}




