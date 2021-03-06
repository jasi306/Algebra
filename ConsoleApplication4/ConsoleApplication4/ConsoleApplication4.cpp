#include "pch.h"
#include <iostream>

using namespace std;

class vector;

class vector{
public:

	int wymiar;
	float* wartosci;

	
	
	vector(int wymiarS, float* wartosciS) {
		wymiar = wymiarS;
		wartosci = wartosciS;
	}
	vector() {
		wymiar = 0;
		wartosci = NULL;
	}
	vector(int wymiarS) {
		wymiar = wymiarS;
		wartosci = new float[wymiar];
		for (int i = 0; i < wymiar; ++i) *(wartosci + i) = 0;
	}
	

	void setWymiar(int W) {
		
		if (wartosci != NULL) delete wartosci;

		wartosci =new float[wymiar];
		wymiar = W;
	}
	int getWymiar() {
		return wymiar;
	}
	/*
	float getValue(int i) {
		return *(wartosci+i);
	}
	
	void setValue(int i, float in) {
		*(wartosci + i) = in;
	}
	void setValue(vector in) {
		if (this->wymiar != in.wymiar) {
			printf("blad");
			return;
		}

		for (int i = 0; i < in.wymiar; ++i) {
			*(wartosci + i) = *(in.wartosci+i);
		}
	}
	
	void changeValue(int i, float in) {
		*(wartosci + i) += in;
	}
	
	void changeValue(vector in) {
		for (int i = 0; i < in.wymiar; ++i)
			*(wartosci + i) += *(in.wartosci + i);
	}
	*/
	vector proj( vector &u) {
		
		if ((u * u) == 0) printf("dzielenie przez 0");
		printf("\n%p\n", &u);
		return u * ((*this * u) / (u * u));
	}


	float operator *(const vector & v) //iloczyn skalarny
	{
		float suma = 0;
		
		for (int i = 0; i < v.wymiar; ++i) {
			suma += *(this->wartosci + i) * *(v.wartosci + i);
		}
		return suma;
	}

	vector operator *(const float & d)
	{
		vector out;
		//out.cp(*this);
		out = *this;
		for (int i = 0; i < this->wymiar; ++i) {
			*(out.wartosci + i) *= d;
		}
		//this->wypisz();
		return out;
	}

	vector operator +(const vector & v)
	{
		if (this->wymiar != v.wymiar) {
			printf("blad\n");
		}

		vector out(v.wymiar);

		for (int i = 0; i < v.wymiar; ++i) {
			*(out.wartosci + i) = *(this->wartosci + i) + *(v.wartosci + i);
		}
		return out;

	}
	
	vector operator -(const vector & v)
	{
		if (this->wymiar != v.wymiar) {
			printf("blad\n");
		}

		vector out(v.wymiar);

		for (int i = 0; i < v.wymiar; ++i) {
			*(out.wartosci + i) = *(this->wartosci + i) - *(v.wartosci + i);
		}
		return out;

	}
	
	void cp(vector v) {


		printf("\nkopjowanie %p = %p\n", this, v.wartosci);

		if (wymiar != v.wymiar) {
			this->setWymiar(v.wymiar);
		}

		for (int i = 0; i < wymiar; ++i) {
			*(this->wartosci + i) = *(v.wartosci + i);
		}


	}

	void operator =(const vector & v)
	{

		printf("\nprzyrownanie %p = %p\n", this,v.wartosci);

		if (wymiar != v.wymiar) {
			this->setWymiar(v.wymiar);
		}
		
		for (int i = 0; i < wymiar; ++i) {
			*(this->wartosci+i) = *(v.wartosci+i);
		}
		
	}

	void wczytaj(int W) {
		wymiar = W;
		wartosci = new float[wymiar];
		for (int i = 0; i < wymiar; ++i) {
			printf("\npodaj %d wartosc wektora.\n",i+1);
			cin >> *(wartosci + i);


		}
	}
	void wypisz() {
		cout.precision(2);

		for(int i=0;i<wymiar;++i) cout << fixed << "wartosc wektora " <<  i+1 << " " << *(wartosci + i)<<endl;
		cout << endl;
	}
	
	~vector() {
		printf("\n usuwanie\n");
		printf("\n \t\twartosci  U  adress %p \n", wartosci);
		delete wartosci;
	}
};






class base {
public:
	int ilosc_wektorow;
	vector* vectors;

	/*
	base OGS() {

		
		for (int i = 0; i < ilosc_wektorow; ++i) {
			printf("\n wartosci |in| Po adress %p %d \n", (vectors + i)->wartosci, i);

		}
		printf("poczatek OGS\n");
		wypisz();
		for (int i = 0; i < ilosc_wektorow -1; ++i) {
			if ((vectors + i)->getWymiar() != (vectors + i + 1)->getWymiar()) {
				printf("wymary wektorow sie nie zgadza\n");
				return base();
			}
		}

		base *out;
		out = new base();
		out->ilosc_wektorow = ilosc_wektorow;
		out->vectors = new vector[ilosc_wektorow]();

		
		for (int i = 0; i < out->ilosc_wektorow; ++i) {
			//printf("\n wektor adress %p %d \n", out->vectors + i, i);
			//printf("\n wartosci  P  adress %p %d \n",  (out->vectors+i)->wartosci, i);
			(out->vectors+i)->setWymiar(vectors->getWymiar());  //pierwszy
			printf("\n wartosci |out| Po adress %p %d \n", (out->vectors + i)->wartosci, i);
		}
		
		//liczenie
		for (int i = 0; i < out->ilosc_wektorow; ++i) {
			printf("\n przed proj\n");
			
			printf("\n wartosci pz adress %p %d \n", (out->vectors + i)->wartosci, i);
			(vectors + i)->wypisz();
			*(out->vectors + i) = *(vectors + i);
			(out->vectors + i)->wypisz();
			for (int j = 0; j < i; ++j) {
				printf("%d - %d\n", i, j);
				
				
				*(out->vectors + i);// = *(out->vectors + i) - (vectors + i)->proj(*(out->vectors + j));

				
			}
			printf("\n po proj\n");
			printf("\n wartosci po adress %p %d \n", (out->vectors + i)->wartosci, i);

			printf("\n");
		}

		
		return *out;
	}*/
	void OGS() {
		

	




		//for (int i = 0; i < ilosc_wektorow; ++i) {
			//printf("\n wartosci |in| Po adress %p %d \n", (vectors + i)->wartosci, i);
		//}

		printf("poczatek OGS\n");

		for (int i = 0; i < ilosc_wektorow - 1; ++i) {
			if ((vectors + i)->getWymiar() != (vectors + i + 1)->getWymiar()) {
				printf("wymary wektorow sie nie zgadza\n");
				
			}
		}


		//liczenie
		for (int i = 0; i < ilosc_wektorow; ++i) {
			
			//printf("\n wartosci pz adress %p %d \n", (vectors + i)->wartosci, i);
		
			for (int j = 0; j < i; ++j) {

				printf("\npoczatek\n");
				printf("%d - %d\n", i, j);
				*(vectors + i) - ((vectors + i)->proj(*(vectors + j)));
				*(vectors + i) - ((vectors + i)->proj(*(vectors + j)));
				//vector temp = *(vectors + i) - (vectors + i)->proj(*(vectors + j));
				
				//printf("%mhmm %p\n", &temp);

				//*(vectors + i) = temp;

				printf("\nkoniec\n");
			}
			
			//printf("\n wartosci po adress %p %d \n", (vectors + i)->wartosci, i);

			printf("\n");
		}
	}


	



	bool check() {
		if (1) {


		}


	}

	base() {
		vectors = NULL;
		ilosc_wektorow = 0;
	}
	/*
	base(FILE* plik, FILE* plik1) {
		wczytaj(plik, plik1);
	}*/


	void wczytaj() {
		int size;
		printf("ile wektorow\n");
		scanf_s("%d",&ilosc_wektorow);
		printf("ile wymiarow\n");
		scanf_s("%d",&size);
		vectors = new vector[ilosc_wektorow];
		for (int i = 0; i < ilosc_wektorow; ++i) {
			printf("Wektor nr %d", i + 1);
			(vectors + i)->wczytaj(size);
		}
	}

	/*
	void wczytaj(FILE* plik, FILE* plik1) {
		
		char c;
		int Vnr = -1;
		int Vpos = 0;
		int dlugosc_wektorow[300];
		do {
			fscanf_s(plik, "%c", &c);
			switch (c) {
			case ' ': {
				char temp[200];
				fscanf_s(plik, "%s", temp, 200);

				Vpos++;
				break;
			}
			case '\t': {
				dlugosc_wektorow[Vnr] = Vpos;
				Vpos = 0;
				Vnr++;


				char temp[200];
				fscanf_s(plik, "%s", temp, 200);

				Vpos++;

				break;
			}
			case '\n':
				dlugosc_wektorow[Vnr] = Vpos;
				break;
			default:
				printf("blad %c %d %d\n", c, Vnr, Vpos);
			}
		} while (c != '\n');
		

		vectors = new vector[Vnr+1];
		for (int i = 0; i < Vnr+1; ++i) {
			printf("\n\n%d_%d\n",i, dlugosc_wektorow[i]);
			(vectors + i)->setWymiar(dlugosc_wektorow[i]);
		}
		ilosc_wektorow = Vnr + 1;


		//system("pause");
		
		Vnr = -1;
		Vpos = 0;
		do {
			fscanf_s(plik1, "%c", &c);
			switch (c) {
			case ' ': {
				char temp[200];
				fscanf_s(plik1, "%s", temp, 200);

				printf("\n set: %f to w: %d pos: %d", atof(temp), Vnr, Vpos);

				(vectors + Vnr)->setValue(Vpos, atof(temp));
				//printf("\n-%f-%f-\n", (vectors + Vnr)->getValue(Vpos), atof(temp));
				Vpos++;
				break;
			}
			case '\t': {
				Vpos = 0;
				Vnr++;


				char temp[200];
				fscanf_s(plik1, "%s", temp, 200);

				printf("\n set: %f to w: %d pos: %d", atof(temp), Vnr, Vpos);

				(vectors + Vnr)->setValue(Vpos, atof(temp));
				//printf("\n-%f-%f-\n", (vectors + Vnr)->getValue(Vpos) , atof(temp));
				Vpos++;
				break;
			}
			case '\n':
				break;
			default:
				printf("blad %c %d %d\n", c, Vnr, Vpos);
			}
		} while (c != '\n');
		//system("pause");
	}
	*/
	void wypisz() {
		printf("wypisywanie\n");
		printf("//////////");
		for (int i = 0; i < ilosc_wektorow; ++i) {

			printf("\n po wypisz\n");
			printf("\n wartosci adress %p %d \n", (vectors + i)->wartosci, i);

			printf("wektor %d\n\n", i);
			(vectors+i)->wypisz();
		}
		printf("\\\\\\\\\\");
	}

	~base() {
		//delete vectors;
	}
};





void files_close(FILE* plik, FILE* plik1) {
	fclose(plik);
	fclose(plik1);
}



int main()
{
	/*
	vector *A, *B;
	float * a = new float[2];
	*a = 2;
	*(a + 1) = 2;
	float * b = new float[2];
	*b = 2;
	*(b + 1) = 1;
	A = new vector(2, a);
	B = new vector(2, b);
	float temp;
	//vector C = A->proj( *B);
	vector C = *B+ *A;

	temp = *A * *B;
	printf("\n%f\n", temp);
	(*A * -1).wypisz();
	A->wypisz();
	B->wypisz();
	A->proj(*B).wypisz();
	B->proj(C).wypisz();
	C.wypisz();
	A->wypisz();
	B->wypisz();
	*/

	/*
	string link = "zadania.txt";
	FILE *plik, *plik1;
	errno_t err;
	if ((err = fopen_s(&plik, link.c_str(), "r")) != 0) {
		printf("blad wczytywania pliku.\n");
	}
	if ((err = fopen_s(&plik1, link.c_str(), "r")) != 0) {
		printf("blad wczytywania pliku.\n");
	}*/
	

	/*
	base baza;
	baza.wczytaj();

	base out = baza.OGS();
	printf("Ostatnie.\n");
	out.wypisz();
	*/
	base baza;
	baza.wczytaj();

	baza.OGS();
	baza.wypisz();

//	delete &baza;
	//delete &out;

	system("pause");
    
}