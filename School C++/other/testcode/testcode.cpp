/*#include <iostream.h>
#include <stdio.h>
#include <io.h>
#include <time.h>

void main( void )
{
    struct _finddata_t c_file;
    long hFile;

    /* Find first .c file in current directory 
    if( (hFile = _findfirst( "", &c_file )) == -1L )
       printf( "No *.c files in current directory!\n" );
   else
   {
            printf( "Listing of .c files\n\n" );
            printf( "\nRDO HID SYS ARC  FILE         DATE %25c SIZE\n", ' ' );
            printf( "--- --- --- ---  ----         ---- %25c ----\n", ' ' );
            printf( ( c_file.attrib & _A_RDONLY ) ? " Y  " : " N  " );
            printf( ( c_file.attrib & _A_SYSTEM ) ? " Y  " : " N  " );
            printf( ( c_file.attrib & _A_HIDDEN ) ? " Y  " : " N  " );
            printf( ( c_file.attrib & _A_ARCH )   ? " Y  " : " N  " );
            printf( " %-12s %.24s  %9ld\n",
               c_file.name, ctime( &( c_file.time_write ) ), c_file.size );

            /* Find the rest of the .c files 
            while( _findnext( hFile, &c_file ) == 0 )
            {
                printf( ( c_file.attrib & _A_RDONLY ) ? " Y  " : " N  " );
                printf( ( c_file.attrib & _A_SYSTEM ) ? " Y  " : " N  " );
                printf( ( c_file.attrib & _A_HIDDEN ) ? " Y  " : " N  " );
                printf( ( c_file.attrib & _A_ARCH )   ? " Y  " : " N  " );
                printf( " %-12s %.24s  %9ld\n",
                   c_file.name, ctime( &( c_file.time_write ) ), c_file.size );
            }

       _findclose( hFile );
   }
}
*/

/*#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <direct.h>

char full[_MAX_PATH], part[_MAX_PATH];

void main( void )
{
   while( 1 )
   {
      printf( "Enter partial path or ENTER to quit: " );
      gets( part );
      if( part[0] == 0 )
         break;

      if( _fullpath( full, part, _MAX_PATH ) != NULL )
         printf( "Full path is: %s\n", full );
      else
         printf( "Invalid path\n" );
   }
}
*/

/*#include <stdio.h>
#include <conio.h>
#include <direct.h>
#include <stdlib.h>
#include <ctype.h>

void main( void )
{
   int ch, drive, curdrive;
   static char path[_MAX_PATH];

   /* Save current drive. 
   curdrive = _getdrive();

   printf( "Available drives are: \n" );

   /* If we can switch to the drive, it exists. 
   for( drive = 1; drive <= 26; drive++ )
      if( !_chdrive( drive ) )
         printf( "%c: ", drive + 'A' - 1 );

   while( 1 )
   {
      printf( "\nType drive letter to check or ESC to quit: " );
      ch = _getch();
      if( ch == 27 )
         break;
      if( isalpha( ch ) )
         _putch( ch );
      if( _getdcwd( toupper( ch ) - 'A' + 1, path, _MAX_PATH ) != NULL )
         printf( "\nCurrent directory on that drive is %s\n", path );
   }

   /* Restore original drive.
   _chdrive( curdrive );
   printf( "\n" );
}*/

/*#include <direct.h>
#include <stdlib.h>
#include <stdio.h>

void main( void )
{
   if( _mkdir( "\\testtmp" ) == 0 )
   {
      printf( "Directory '\\testtmp' was successfully created\n" );
      system( "dir \\testtmp" );
      /*if( _rmdir( "\\testtmp" ) == 0 )
        printf( "Directory '\\testtmp' was successfully removed\n"  );
      else
         printf( "Problem removing directory '\\testtmp'\n" );*
   }
   else
      printf( "Problem creating directory '\\testtmp'\n" );
}*/
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>

#define MAX_THREADS  32

/* getrandom returns a random number between min and max, which must be in
 * integer range.
 */
#define getrandom( min, max ) ((rand() % (int)(((max) + 1) - (min))) + (min))

void main( void );                     /* Thread 1: main */
void KbdFunc( void  );                 /* Keyboard input, thread dispatch */
void BounceProc( char * MyID );        /* Threads 2 to n: display */
void ClearScreen( void );              /* Screen clear */
void ShutDown( void );                 /* Program shutdown */
void WriteTitle( int ThreadNum );      /* Display title bar information */

HANDLE  hConsoleOut;                   /* Handle to the console */
HANDLE  hRunMutex;                     /* "Keep Running" mutex */
HANDLE  hScreenMutex;                  /* "Screen update" mutex  */
int     ThreadNr;                      /* Number of threads started */
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;   /* Console information */


void main()                            /* Thread One */
{
    /* Get display screen information & clear the screen.*/
    hConsoleOut = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleScreenBufferInfo( hConsoleOut, &csbiInfo );
    ClearScreen();
    WriteTitle( 0 );
    /* Create the mutexes and reset thread count. */
    hScreenMutex = CreateMutex( NULL, FALSE, NULL );   /* Cleared */
    hRunMutex = CreateMutex( NULL, TRUE, NULL );       /* Set */
    ThreadNr = 0;

    /* Start waiting for keyboard input to dispatch threads or exit. */
    KbdFunc();

    /* All threads done. Clean up handles. */
    CloseHandle( hScreenMutex );
    CloseHandle( hRunMutex );
    CloseHandle( hConsoleOut );
}

void ShutDown( void )                  /* Shut down threads */
{
    while ( ThreadNr > 0 )
    {
            /* Tell thread to die and record its death. */
            ReleaseMutex( hRunMutex );
            ThreadNr--;   
    }
    /* Clean up display when done */
    WaitForSingleObject( hScreenMutex, INFINITE );
    ClearScreen();
}

void KbdFunc( void )                   /* Dispatch and count threads. */
{
    int         KeyInfo;

    do
    {
        KeyInfo = _getch();
        if( tolower( KeyInfo ) == 'a' && ThreadNr < MAX_THREADS )
        {
            ThreadNr++;
            _beginthread( BounceProc, 0, &ThreadNr );
            WriteTitle( ThreadNr );
        }
    } while( tolower( KeyInfo ) != 'q' );

    ShutDown();
}

void BounceProc( char *MyID )
{
    char      MyCell, OldCell;
    WORD      MyAttrib, OldAttrib;
    char      BlankCell = 0x20;
    COORD     Coords, Delta;
    COORD     Old = {0,0};
    DWORD     Dummy;

/* Generate update increments and initial display coordinates. */
    srand( (unsigned) *MyID * 3 );
    Coords.X = getrandom( 0, csbiInfo.dwSize.X - 1 );
    Coords.Y = getrandom( 0, csbiInfo.dwSize.Y - 1 );
    Delta.X = getrandom( -3, 3 );
    Delta.Y = getrandom( -3, 3 );

    /* Set up "happy face" & generate color attribute from thread number.*/
    if( *MyID > 16)
        MyCell = 0x01;                 /* outline face */
    else
        MyCell = 0x02;                 /* solid face */
    MyAttrib =  *MyID & 0x0F;          /* force black background */

    do
    {
        /* Wait for display to be available, then lock it. */
        WaitForSingleObject( hScreenMutex, INFINITE );

        /* If we still occupy the old screen position, blank it out. */
        ReadConsoleOutputCharacter( hConsoleOut, &OldCell, 1, Old, &Dummy );
        ReadConsoleOutputAttribute( hConsoleOut, &OldAttrib, 1, Old, &Dummy );
        if (( OldCell == MyCell ) && (OldAttrib == MyAttrib))
            WriteConsoleOutputCharacter( hConsoleOut, &BlankCell, 1, Old, &Dummy );

        /* Draw new face, then clear screen lock */
        WriteConsoleOutputCharacter( hConsoleOut, &MyCell, 1, Coords, &Dummy );
        WriteConsoleOutputAttribute( hConsoleOut, &MyAttrib, 1, Coords, &Dummy );
        ReleaseMutex( hScreenMutex );

        /* Increment the coordinates for next placement of the block. */
        Old.X = Coords.X;
        Old.Y = Coords.Y;
        Coords.X += Delta.X;
        Coords.Y += Delta.Y;

        /* If we are about to go off the screen, reverse direction */
        if( Coords.X < 0 || Coords.X >= csbiInfo.dwSize.X )
        {
            Delta.X = -Delta.X;
            Beep( 400, 50 );
        }
        if( Coords.Y < 0 || Coords.Y > csbiInfo.dwSize.Y )
        {
            Delta.Y = -Delta.Y;
            Beep( 600, 50 );
        }
    }
    /* Repeat while RunMutex is still taken. */
    while ( WaitForSingleObject( hRunMutex, 75L ) == WAIT_TIMEOUT );

}

void WriteTitle( int ThreadNum )
{
    char    NThreadMsg[80];

    sprintf( NThreadMsg, "Threads running: %02d.  Press 'A' to start a thread,'Q' to quit.", ThreadNum );
    SetConsoleTitle( NThreadMsg );
}

void ClearScreen( void )
{
    DWORD    dummy;
    COORD    Home = { 0, 0 };
    FillConsoleOutputCharacter( hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy );
}




