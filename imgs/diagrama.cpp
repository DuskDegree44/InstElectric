#include <iostream>
#include <string>

using namespace std;
int main()
{
   string raptor_prompt_variable_zzyz;
   ?? climaencentido;
   ?? temperatura2;
   ?? luzemitiendo;
   ?? temperatura;
   ?? climaencentido2;
   ?? modo;
   ?? luzemitiendo2;
   ?? directa;
   ?? presencia2;
   ?? directo;
   ?? presencia;

   directo =true;
   raptor_prompt_variable_zzyz =1;
   cout << raptor_prompt_variable_zzyz << endl;
   cin >> modo;
   raptor_prompt_variable_zzyz =1;
   cout << raptor_prompt_variable_zzyz << endl;
   cin >> directa;
   while (!(modo==0))
   {
      if (directa==1)
      {
         temperatura =26;
         presencia =1;
         luzemitiendo =65;
         climaencentido =false;
         temperatura2 =17;
         presencia2 =0;
         luzemitiendo2 =10;
         climaencentido2 =true;
         cout << "Mandando datos a la computadora: "+temperatura+temperatura2+presencia+presencia2+luzemitiendo+luzemitiendo2+climaencentido+climaencentido2 << endl;      }
      else
      {
         temperatura =0;
         presencia =0;
         luzemitiendo =0;
         climaencentido =false;
         cout << "Mandando datos a la computadora: "+temperatura+presencia+luzemitiendo+climaencentido << endl;      }
   }

   return 0;
}
