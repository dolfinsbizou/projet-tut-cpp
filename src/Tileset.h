#ifndef _BOMBERMAN_TILESET_H_
#define _BOMBERMAN_TILESET_H_

#include "Globals.h"
#include "MapTile.h"
#include "Tile.h"

/*! \brief a Tileset stores information about a set of Tile after a sf::Texture
 */
class Tileset
{
private:

	const sf::Texture *m_texture; //!< pointer to the sf::Texture of the Tileset
	int m_rows; //!< number of rows in the sf::Texture
	int m_cols; //!< number of columns in the sf::Texture
	int m_width; //!< width of a Tile in the sf::Texture
	int m_height; //!< height of a Tile in the sf::Texture
	int m_displayWidth; //!< display width of a Tile
	int m_displayHeight; //!< display height of a Tile

public:

	/*! \brief default constructor
	 *  \param tex pointer to the sf::Texture of the Tileset
	 *  \param rows number of rows
	 *  \param cols number of columns
	 *  \param width width of a Tile
	 *  \param height height of a Tile
	 *  \param displayWidth display width
	 *  \param displayHeight display height
	 */
	Tileset(const sf::Texture *tex, int rows, int cols, int width, int height, int displayWidth, int displayHeight);

	template<typename T = Tile>
	/*! \brief create a Tile with a single sf::Sprite at given coordinates on the sf::Texture (in terms of rows and cols, not pixels)
	 *  \param i x value
	 *  \param j y value
	 */
	T *createTile(int i, int j, TileType ty=TileType::DEFAULT, bool c=NULL, bool b=NULL)
	{
		sf::Sprite *newSprite = new sf::Sprite();
		cout << "** Setting up the sf::Sprite " << newSprite << " via Tileset " << this << endl;
		newSprite->setTexture(*m_texture);
		newSprite->setTextureRect(sf::IntRect(
								(i-1)*m_width,
								(j-1)*m_height,
								m_width,
								m_height));
		newSprite->setScale((float)m_displayWidth/(float)m_width,
						(float)m_displayHeight/(float)m_height);
		cout << "test" << endl;
		return new T(*newSprite, ty);
	}
	
	template<typename T = Tile>
	/*! \brief create a Tile with multiples sf::Sprite at given coordinates on the sf::Texture (in terms of rows and cols, not pixels)
	 *  \param i x values
	 *  \param j y values
	 */
	T *createTile(vector<int> i,vector <int> j, TileType ty=TileType::DEFAULT, bool c=NULL, bool b=NULL)
	{
		T *t = new T(ty);
		sf::Sprite *newSprite = NULL;
		for(unsigned int k = 0 ; (k < i.size()) && (k < j.size()) ; k++)
		{
			newSprite = new sf::Sprite();
			cout << "** Setting up the sf::Sprite " << newSprite << " via Tileset " << this << endl;
			newSprite->setTexture(*m_texture);
			newSprite->setTextureRect(sf::IntRect(
									(i[k]-1)*m_width,
									(j[k]-1)*m_height,
									m_width,
									m_height));
			newSprite->setScale((float)m_displayWidth/(float)m_width,
							(float)m_displayHeight/(float)m_height);
			t->addSprite(*newSprite);
		}

		return t;
	}

	/*! \brief getter of m_texture
	 *  \return m_texture
	 */
	const sf::Texture *getTexture();
	/*! \brief getter of m_displayWidth
	 *  \return m_displayWidth
	 */
	int getDisplayWidth();
	/*! \brief getter of m_displayHeight
	 *  \return m_displayHeight
	 */
	int getDisplayHeight();
	/*! \brief getter of m_width
	 *  \return m_width
	 */
	int getWidth();
	/*! \brief getter of m_height
	 *  \return m_height
	 */
	int getHeight();
	/*! \brief getter of m_rows
	 *  \return m_rows
	 */
	int getRows();
	/*! \brief getter of m_cols
	 *  \return m_cols
	 */
	int getCols();
};

#endif //_BOMBERMAN_TILESET_H_
