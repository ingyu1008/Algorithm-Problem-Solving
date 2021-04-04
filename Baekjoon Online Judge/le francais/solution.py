l,k,b,p,_="abcdefghijklmnopqrstuvxyzàçèéêîô",100,80,10,{1:"un",2:"deux",3:"trois"}
_[4]="quatre"
_[5]="cinq"
_[6]="six"
_[7]="sept"
_[8]="huit"
_[9]="neuf"
_[p]="dix"
_[11]="onze"
_[12]="douze"
_[13]="treize"
_[14]="quatorze"
_[15]="quinze"
_[16]="seize"
_[20]="vingt"
_[30]="trente"
_[40]="quarante"
_[50]="cinquante"
_[60]="soixante"
_[b]=_[4]+" "+_[20]
_[k]="cent"
def g(n):
  t=n%p==1 and n>11
  return"mille un"if n==1001 else _[n-n%p]+" et un"if n<70 and t else _[60]+" et onze"if n<72 and t else _[b]+" un"if n<82 and t else _[b]+" onze"if n<92 and t else""if n==0 else _[n]if n<17 else _[n-n%p]+" "+g(n%p)if n<61 else _[60]+" "+g(n-60)if n<b else _[b]+"s"if n==b else _[b]+" "+g(n-b)if n<100 else _[k]+" "+g(n-k)if n<200 else _[n//k]+" "+_[k]+" "+g(n%k)if n%100 else _[n//k]+" "+_[k]+"s"if n<1000 else ""
x=input()
c=sum(y in l for y in x)
a=c-(c%7)
if c%7>=4:a+=7
print("zéro"if a==0 else g(a))