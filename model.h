
type def struct
{
UINT32 bitMap[128];
}BitMap64

type def struct
{
BitMap64 snowBoardPlayer;
int lives;
unsigned int x;
unsigned int y = 200;
unsigned int sidewaysSpeed; /*might have to be UINT32 unfortunatly*/

}snowBoarder;

type def struct
{
BitMap64 tree;
unsigned int x,y;
unsigned int upwardSpeed; 
unsigned int downwardSpeed; 


}tree;
