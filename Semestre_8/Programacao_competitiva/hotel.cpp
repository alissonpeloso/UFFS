#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
using ll = unsigned long long int;
const ll chegada = 0;
const ll saida = 1;
 
ll n;
vector<ll> h;
vector<vector<ll>> eventos;
vector<ll> qLivres;
ll nQuartos = 0;
 
bool ordena_eventos(const vector<ll> &v1, const vector<ll> &v2) {
    if (v1[0] == v2[0]) {
        return v1[1] == chegada;
    }
    return v1[0] < v2[0];
}
 
int main() {
    cin >> n;
 
    for (ll i = 0; i < n; i++) {
        vector<ll> eventoChegada;
        vector<ll> eventoSaida;
 
        ll hEntrada, hSaida;
        cin >> hEntrada >> hSaida;
 
        eventoChegada.push_back(hEntrada);
        eventoChegada.push_back(chegada);
        eventoChegada.push_back(i);
 
        eventoSaida.push_back(hSaida);
        eventoSaida.push_back(saida);
        eventoSaida.push_back(i);
 
        eventos.push_back(eventoChegada);
        eventos.push_back(eventoSaida);
        h.push_back(0);
    }
 
    sort(eventos.begin(), eventos.end(), ordena_eventos);
 
    for (ll i = 0; i < eventos.size(); i++) {
        if (eventos[i][1] == chegada) {
            if (qLivres.size() > 0) {
                ll quarto_removido = qLivres.back();
                qLivres.pop_back();
                h[eventos[i][2]] = quarto_removido;
            } else {
                nQuartos++;
                h[eventos[i][2]] = nQuartos;
            }
        } else {
            qLivres.push_back(h[eventos[i][2]]);
        }
    }
 
    cout << nQuartos << "\n";
 
    for (ll i = 0; i < h.size(); i++) {
        cout << h[i] << " ";
    }
    cout << "\n";
 
    return 0;
}