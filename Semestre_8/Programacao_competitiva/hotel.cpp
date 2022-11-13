#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
vector<vector<ll>> eventos;
vector<ll> quartos;
vector <int> qLivres;
int nQuartos = 0;
ll n;
vector<ll> h;
 
int chegada = 0;
int saida = 1;
 
bool ordenaprimeiro(const vector<ll> &v1, const vector<ll> &v2)
{  
  if(v1[0] == v2[0]) {
    return v1[1] == chegada;
  }
  return v1[0] < v2[0];
}
 
bool essa(const vector<ll> &v1, const ll val)
{
    return v1[0] < val;
}
 
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
      h.push_back(0);
    }
 
    for (ll i = 0; i < n; i++) {
        vector<ll> eventoChegada;
        vector<ll> eventoSaida;
        ll a, b;
        cin >> a >> b;
        eventoChegada.push_back(a);
        eventoChegada.push_back(chegada);
        eventoChegada.push_back(i);
 
        eventoSaida.push_back(b);
        eventoSaida.push_back(saida);
        eventoSaida.push_back(i);
 
        eventos.push_back(eventoChegada);
        eventos.push_back(eventoSaida);
    }

    sort(eventos.begin(), eventos.end(), ordenaprimeiro);
  
    for (ll i = 0; i < eventos.size(); i++) {
      if(eventos[i][1] == chegada){
        if (qLivres.size() > 0){
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

    for(ll i = 0; i < h.size(); i++) {
      cout << h[i] << " "; 
    }
    cout << "\n";

    return 0;
}