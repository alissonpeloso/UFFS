#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<ll>> hospedes;
vector<ll> quartos;
vector<ll> h;

const int ENTRADA = 0;
const int SAIDA = 1;
const int INDEX = 2;
const int VERIFICADO = 3;

bool ordenaprimeiro(const vector<ll> &v1, const vector<ll> &v2)
{
    return v1[0] < v2[0];
}

bool essa(const ll val, const vector<ll> &v1)
{
    if (v1[VERIFICADO] == 1) {
        return false;
    }
    
    return  val < v1[0];
}

void printHospedes() {
    cout << "Hospedes: " << endl;

    for (int i = 0; i < hospedes.size(); i++) {
        cout << hospedes[i][0] << " " << hospedes[i][1] << " " << hospedes[i][2] << " " << hospedes[i][3] << endl;
    }

    cout << endl;
}

void printQuartos() {
    cout << "Quartos: " << endl;

    for (int i = 0; i < quartos.size(); i++) {
        cout << quartos[i] << endl;
    }

    cout << endl;
}

void printH() {
    cout << "H: " << endl;

    for (int i = 0; i < h.size(); i++) {
        cout << h[i] << " ";
    }
    cout << endl << endl;
}

void printAll(){
    printHospedes();
    printQuartos();
    printH();
}

int main()
{
    ll n, sum = 0;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        vector<ll> hospede;
        ll a, b;
        cin >> a >> b;
        hospede.push_back(a);
        hospede.push_back(b);
        hospede.push_back(i);
        hospede.push_back(0); // 0 = não usado, 1 = usado
        hospedes.push_back(hospede);
        h.push_back(0);
    }

    sort(hospedes.begin(), hospedes.end(), ordenaprimeiro);

    quartos.push_back(hospedes[0][SAIDA]);
    hospedes[0][VERIFICADO] = 1;
    h[hospedes[0][INDEX]] = 0;
    ll quarto = 0;

    // printAll();

    while (sum <= n)
    {
        sum++;
        ll i = upper_bound(hospedes.begin(), hospedes.end(), quartos[quarto], essa) - hospedes.begin();
        // cout << "oi boi " << i << endl;
        if (i >= n) {
            quarto++;
            quartos.push_back(0);
            continue;
        }

        else if (hospedes[i][SAIDA] <= quartos[quarto] || i >= n) {
            quarto++;
            quartos.push_back(hospedes[i][SAIDA]);
            hospedes[i][VERIFICADO] = 1;
            h[hospedes[i][INDEX]] = quarto;

            // printAll();

            continue;
        }
        quartos[quarto] = hospedes[i][SAIDA];
        hospedes[i][VERIFICADO] = 1;
        h[hospedes[i][INDEX]] = quarto;
        // printAll();
    }

    cout << quarto << "\n";

    for (auto i: h) {
        cout << i + 1<< " ";
    }

    cout << "\n";

    return 0;
}