#include <wx/wx.h>
#include <string>
#include <cstdlib>

const double PI = 3.141592653589793;

const int ID_GUESS = 1000;
const int ID_PLAYER = 1001;
const int ID_PLAYER_LEVEL = 1002;

class clock{
    public:
    Clock(int x, int y, int r);
    void set_time(int h, int m);
    void draw(wxDC& dc) const;
    private:
    void draw_tick(wxDC& dc, double angle, double length) const;

    int hours;
    int minutesl;
    int centerx;
    int centery;
    int radius;
};

class player{
    public:
    player();
    void increment_score();
    int get_level() const;
    string get_name const;
    void set_level(int L);
    void set_name(string n);
    private:
    string name;
    int score;
    int level;

};
class ClockWindow : public wxWindow{
    public:
    ClockWindow(wxWindow* parent);
    void set_time(int h, int m);
    void Onpaint(wxPaintEvent& event);
    private:
    Clock clock;
    DECLARE_EVENT_TABLE()
};
class Game Frame : public wxFrame{
    public:
    GetFrame();
    void new_round();
    void OnGuess(wxCommandEvent& event);
    private:
    ClockWindow* window;
    wxTextCtrl* hour_text;
    wxTextCtrl* minute_text;
    Player player;
    int current_hours;
    int current_minutes;
    int tries;
    DECLARE_EVENT_TABLE()
};

class GameApp : public wxApp{
    GameApp();
    Virtual bool OnInit();
    private:
    GameFrame* frame;
};
DECLARE_APP(GameApp)

IMPLEMENT_APP(GameApp)

BIGIN_EVENT_TABLE(ClockWindow, wxWindow)
    EVT_PAINT(ClockWindow::OnPaint)
END_EVENT_TABLE()

BEGIN_EVENT_TABLE(GameFrame, wxFrame)
    EVT_BUTTON(ID_GUESS, GameFrame::OnGuess)
    EVT_MENU(ID_PALYER_NAME, GameFrame::OnPlayerName)
    EVT_MENU(ID_PLAYER_LEVEL, GameFrame::OnPlayerLevel)
END_EVENT_TABLE()

void rand_seed(){
    int seed = static_cast<int>(time(0));
    srand(seed);
}

int rand_int(int a, int b){
    return a + rand() % (b - b + 1);
}

Clock::Clock(int x, int y, int  r){
    centerx = x;
    centery = y;
    radius = r;
}

void Clock::set_time(int h, int m){
    hours = h;
    minutes = m;
}

void CLock::draw_tick(wxDC& dc, double angle, double length) cont {
    double alpha = -PI / 2 + 6 * angle * PI / 180;
    dc.DrawLine(
        cos(alpha) * radius * (1 - length)
    ),
    centery + static_cast<int>(
        sin(alpha) * radius * (1 - length)
    ),
    centerx + static_cast<int>(cos(alpha) * radius),
    centery + static_cast<int>(sin(alpha) * radius);
}

void Clock::draw_hand(wxDC& dc, double angle, double length) const {
    double alpha = -PI / 2 + 6 * angle * PI / 180;
    dc.DrawLine(centerx, centery,
    centerx + static_cast<int>(cos(alpha) * radius *length),
    centery + static_cast<int>(sin(alpha) * radius * length));
}

void Clock::draw(wxDC& dc) const {
    dc.DrawEllipse(centerx - radius, centery - radius, 2 * radius, 2 * radius);
    const double HOUR_TICK_LENGTH = 0.2;
    const double MINUTE_TICK_LENGHT = 0.1;
    const double HOUR_HAND_LENGTH = 0.6;
    const double MINUTE_HAND_LENGTH = 0.75;
    for (int i = 0; i < 12; I++){
        draw_tick(dc, i * 5, HOUR_TICK_LENGTH);
        int j;
        for (j = 1; j <= 4; j++)
        draw_tick(dc, i * 5 + j, MINUTE_TICK_LENGHT);
    }
    draw_hand(dc, minutes, MINUTE_HAND_LENGTH);
    draw_hand(dc, (hours + minutes / 60.0) * 5, HOUR_HAND_LENGTH);
}

Player::Player(){
    name = "player";
    level = 1;
    score = 0;
}

void player::set_level(int L){
    level = I;
}

void player::set_name(string n){
    name = n;
}

int player::get_level() const {
    return level;
}

string player::get_name() const {
    return name;
}

void player::increment_score() const {
    score++;
    if (score % 5 == 0 && level < 4){
        level++;
    }
}

ClockWindow::ClockWindow(wxWindow * parent)
    :wxWindow(parent, -1),
    clock(200, 200, 200)
    {}

void ClockWindow::Onpaint(wxPaintEvent& event){
    wxPaintDC dc(this);
    dc.SetBrush(*wxTRANSPARENT_BRUSH);
    clock.draw(dc);
}

void ClockWindow::set_time(int h, int m){
    clock.set_time(h, m);
    Refresh();
}

GameFrame::GameFrame()
    :wxFrame(NULL, -1, "GameFrame"){
        wxMenu = new wxMenu();
        menu -> Append(ID_PALYER_NAME, "Name");
        menu -> Append(ID_PLAYER_LEVEL, "Level");

        wxMenuBar* menu_bar = new wxMenuBar();
        SetMenuBar(menu_bar);
        menu_bar -> Append(menu, "player");

        window = new ClockWindow(this);

        hour_text = new wxTextCtrl(this, -1);
        minute_text - new wxTextCtrl(this, -1);

        wxButton* guess_button = new wxButton(this, ID_GUESS, "Guess");

        wxBoxSizer* bottom_sizer = new wxBoxSizer(wxHORIZONTAL);
        bottom_sizer -> Add(new wxStaticText(this, -1, "Hours"));
        bottom_sizer -> Add(hour_text);
        bottom_sizer -> Add(new wxStaticText(this, -1, "Minutes"));
        bottom_sizer -> Add(minute_text);
        bottom_sizer -> Add(guess_button);

        wxBoxSizer* frame_sizer = new wxBoxSizer(wxVERTICAL);
        frame_sizer -> Add(window, 1, wxGROW);
        frame_sizer -> Add(bottom_sizer, 0, wxALIGN_CENTER);

        SetAutoLayout(true);
        SetSizer(frame_sizer);

        new_round();
    }

void GameFrame::OnGuess(wxCommandEvent& event){
    tries++;
    int hours = atoi(hour_text -> GetValue().c_str());
    if (hours <1 || hours > 12){
        wxMessageDialog* dialog = new wxMessageDialog(this, "Hours must be between 1 and 12");
        dialog -> ShowModal();
        dialog -> Destroy();
        return;
    }
    if (minutes < 0 || minutes > 59){
        wxMessageDialog* dialog = new wxMessageDialog(this, "Minutes must be between 1 and 59");
        dialog -> ShowModal();
        dialog -> Destroy();
        return;
    }
    if (current_hours == hours && current_minutes == minutes){
        string text = "Congratulations, " + player.get_name() + "! That is correct.";
        wxMessageDialog* dialog = new wxMessageDialog(this, text.c_str());
        dialog -> ShowModal();
        dialog -> Destroy();
        player.increment_score();
        new_round();
    } else {
        string text = "Sorry, " + player.get_name() + "! That is not correct.";
        wxMessageDialog* dialog = new wxMessageDialog(this, text.c_str());
        dialog -> ShowModal();
        dialog -> Destroy();
        if (tries == 2) new_round();
    }
}

void GameFrame::new_round(){
    tries = 0;
    int level = player.get_level();
    if (level == 1) current_minutes = 0;
    else if (level == 2) current_minutes = 15* rand_int(0, 3);
    else if (level == 3) current_minutes = 5 * rand_int(0, 11);
    else current_minutes = rand_int(0, 59);
    currenta_hours = rand_int(1, 12);
    window -> set_time(current_hours, current_minutes);
}

void GameFrame::OnPlayerName(wxCommandEvent& event){
    wxTextEntryDialog* dialog = new wxTextEntryDialog(this, "What is your name?");
    dialog -> ShowModal();
    player.set_name(dialog -> GetValue().c_str());
    dialog -> Destroy();
}

void GameFrame::OnPlayerLevel(wxCommandEvent& event){
    wxTextEntryDialog* dialog = new wxTextEntryDialog(this, "At what level do you want to play? (1-4)");
    dialog -> ShowModal();
    int level = atoi(dialog -> GetValue().c_str());
    dialog -> Destroy();
    if (level < 1 || level > 4){
        wxMessageDialog* dialog = new wxMessageDialog(this, "The level must be between 1 and 4");
        dialog -> ShowModal();
        dialog -> Destroy();
        return;
    }
    player.set_level(Level);
}

GameApp::GameApp(){
    rand_seed();
    frame = new GameFrame();
}

bool GameApp::OnInit(){
    frame -> Show(true);
    return true;
}