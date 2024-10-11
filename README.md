# Libft42

La primera asignación de la escuela 42, libft, trata sobre aprender cómo funcionan las funciones estándar de la programación en C, escribiéndolas desde cero y creando nuestra propia librería.

Libft es un proyecto muy importante, ya que esta librería se usará en futuras asignaciones de la escuela 42. Si eres estudiante de 42, te recomiendo encarecidamente que pases por el proceso de prueba y error de escribir tu propio código y probarlo tú mismo, en lugar de copiar y pegar código que solo entiendes a medias. ¡Si superaste la piscine, no hay razón para que no puedas resolver este proyecto por tu cuenta! Sé paciente y meticuloso.

Estado: Finalizado: 2024-10. Nota: 125/100.

Uso:
make para compilar las funciones obligatorias.
make bonus para compilar con las funciones adicionales.

Funciones incluidas:

Funciones obligatorias: Las funciones obligatorias de libft son funciones de la librería estándar de C o de otras funciones útiles. Principalmente son útiles para la manipulación de caracteres, cadenas y memoria. Estas 34 funciones obligatorias deben hacerse correctamente para obtener una calificación del 100%.

### ***Parte 1 - Funciones Básicas***

- **Libreria → libft.h**
    
    ```c
    #ifndef LIBFT_H
    # define LIBFT_H
    
    # include <stddef.h>
    # include <stdlib.h>
    # include <limits.h>
    # include <stdio.h>
    # include <unistd.h>
    
    // Funciones de verificación de caracteres
    int		ft_isalnum(int c);
    int		ft_isalpha(int c);
    int		ft_isascii(int c);
    int		ft_isdigit(int c);
    int		ft_isprint(int c);
    int		ft_tolower(int c);
    int		ft_toupper(int c);
    char	ft_adapt_toupper(unsigned int index, char c);
    void	ft_adapt_toupper2(unsigned int i, char *c);
    
    // Funciones de manipulación de memoria
    void	ft_bzero(void *s, size_t n);
    void	*ft_calloc(size_t count, size_t size);
    void	*ft_memchr(const void *s, int c, size_t n);
    int		ft_memcmp(const void *s1, const void *s2, size_t n);
    void	*ft_memcpy(void *dst, const void *src, unsigned int n);
    void	*ft_memmove(void *dest, const void *src, size_t len);
    void	*ft_memset(void *b, int c, size_t len);
    
    // Funciones de manipulación de cadenas
    int		ft_atoi(const char *str);
    char	*ft_strchr(const char *s, int c);
    size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
    size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
    size_t	ft_strlen(const char *s);
    int		ft_strncmp(const char *s1, const char *s2, size_t n);
    char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
    char	*ft_strrchr(const char *s, int c);
    char	*ft_strdup(const char *s1);
    
    // Funciones de manipulación de cadenas adicionales
    char	*ft_strtrim(char const *s1, char const *set);
    char	*ft_strjoin(char const *s1, char const *s2);
    char	**ft_split(char const *s, char c);
    char	*ft_itoa(int n);
    void	ft_putstr_fd(char *s, int fd);
    void	ft_putendl_fd(char *s, int fd);
    void	ft_putchar_fd(char c, int fd);
    void	ft_putnbr_fd(int n, int fd);
    char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
    char	*ft_substr(char const *s, unsigned int start, size_t len);
    void	ft_striteri(char *s, void (*f)(unsigned int, char*));
    
    // Estructura de nodo de lista enlazada
    typedef struct s_list
    {
    	void			*content;
    	struct s_list	*next;
    }	t_list;
    
    // Funciones bonus con nodos
    t_list	*ft_lstnew(void *content);
    void	ft_lstadd_front(t_list **lst, t_list *new);
    int		ft_lstsize(t_list *lst);
    t_list	*ft_lstlast(t_list *lst);
    void	ft_lstadd_back(t_list **lst, t_list *new);
    void	ft_lstdelone(t_list *lst, void (*del)(void*));
    void	ft_lstclear(t_list **lst, void (*del)(void*));
    void	ft_lstiter(t_list *lst, void (*f)(void*));
    t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
    
    #endif
    ```
    
- **main.c** (Simplemente para testear el código.)
    
    ```jsx
    #include "libft.h"
    
    int main(void)
    {
        char    *str;
        char    buffer[50];
        void    *mem;
        int     num;
    
        // Pruebas para funciones de verificacion de caracteres
        printf("ft_isalnum('A') = %d\n", ft_isalnum('A'));
        printf("ft_isalpha('a') = %d\n", ft_isalpha('a'));
        printf("ft_isascii(128) = %d\n", ft_isascii(128));
        printf("ft_isdigit('5') = %d\n", ft_isdigit('5'));
        printf("ft_isprint(31) = %d\n", ft_isprint(31));
        printf("ft_tolower('A') = %c\n", ft_tolower('A'));
        printf("ft_toupper('a') = %c\n", ft_toupper('a'));
    
        // Pruebas para funciones de manipulacion de memoria
        mem = malloc(20);
        ft_bzero(mem, 20);
        printf("ft_bzero: %s\n", (char *)mem);
        free(mem);
    
        mem = ft_calloc(5, 4);
        printf("ft_calloc: %p\n", mem);
        free(mem);
    
        str = "memchr test string";
        mem = ft_memchr(str, 't', ft_strlen(str));
        printf("ft_memchr: %s\n", (char *)mem);
    
        str = "memcmp test";
        printf("ft_memcmp(\"memcmp test\", \"memcmp t\", 7) = %d\n", ft_memcmp(str, "memcmp t", 7));
    
        str = "memcpy test";
        ft_memcpy(buffer, str, 11);
        printf("ft_memcpy: %s\n", buffer);
    
        str = "memmove test";
        ft_memmove(buffer, str, 12);
        printf("ft_memmove: %s\n", buffer);
    
        ft_memset(buffer, 'A', 10);
        buffer[10] = '\0';
        printf("ft_memset: %s\n", buffer);
    
        // Pruebas para funciones de manipulacion de cadenas
        str = "12345";
        num = ft_atoi(str);
        printf("ft_atoi(\"12345\") = %d\n", num);
    
        str = "strchr test";
        printf("ft_strchr(\"strchr test\", 't') = %s\n", ft_strchr(str, 't'));
    
        str = "strlcat test";
        ft_strlcat(buffer, str, sizeof(buffer));
        printf("ft_strlcat: %s\n", buffer);
    
        str = "strlcpy test";
        ft_strlcpy(buffer, str, sizeof(buffer));
        printf("ft_strlcpy: %s\n", buffer);
    
        str = "strlen test";
        printf("ft_strlen(\"strlen test\") = %lu\n", ft_strlen(str));
    
        printf("ft_strncmp(\"abc\", \"abcde\", 3) = %d\n", ft_strncmp("abc", "abcde", 3));
    
        str = "haystack and needle";
        printf("ft_strnstr(\"haystack and needle\", \"needle\", 20) = %s\n", ft_strnstr(str, "needle", 20));
    
        str = "strrchr test";
        printf("ft_strrchr(\"strrchr test\", 't') = %s\n", ft_strrchr(str, 't'));
    
        str = "strdup test";
        char *dup = ft_strdup(str);
        printf("ft_strdup: %s\n", dup);
        free(dup);
    
        // Pruebas para funciones de manipulación de cadenas adicionales
        str = "   Hello, World!   ";
        char *trimmed = ft_strtrim(str, " ");
        printf("ft_strtrim: \"%s\"\n", trimmed);
        free(trimmed);
    
        char *s1 = "Hello, ";
        char *s2 = "World!";
        char *joined = ft_strjoin(s1, s2);
        printf("ft_strjoin: %s\n", joined);
        free(joined);
    
        char *itoa_result = ft_itoa(42);
        printf("ft_itoa(42) = %s\n", itoa_result);
        free(itoa_result);
    
        // Pruebas para funciones de salida
        printf("ft_putstr_fd:\n");
        ft_putstr_fd("Hello, World!\n", 1);
        
        printf("ft_putendl_fd:\n");
        ft_putendl_fd("Hello, World!", 1);
        
        printf("ft_putchar_fd:\n");
        ft_putchar_fd('A', 1);
        printf("\n");
        
        printf("ft_putnbr_fd:\n");
        ft_putnbr_fd(12345, 1);
        printf("\n");
    
        // Pruebas para funciones que utilizan un callback
        char *str_mapi = ft_strmapi("Hello", ft_adapt_toupper);
        printf("ft_strmapi: %s\n", str_mapi);
        free(str_mapi);
    
        char *substr = ft_substr("Hello, World!", 7, 5);
        printf("ft_substr: %s\n", substr);
        free(substr);
    
    	char str_iteri[] = "hello world";
        printf("Original: %s\n", str_iteri);
        ft_striteri(str_iteri, ft_adapt_toupper2);
        printf("ft_striteri: %s\n", str_iteri);
    
        return (0);
    }
    
    ```
    
    Tambien esta el main del **ft_lstnew_bonus y del ft_lstmap_bonus** abajo:
    

**is_  Funciones de verificación de caracteres.**

- **isalnum** (Verifica que si el un carácter alfanumérico).
    
    ```c
    
    int	ft_isalpha(int c);
    
    int	ft_isdigit(int c);
    
    int	ft_isalnum(int c)
    {
    	if (ft_isalpha(c) || ft_isdigit(c))
    		return (1);
    	return (0);
    }
    
    ```
    
- **isalpha** (La función verifica si el valor de `c` está entre las letras)
    
    ```c
    int	ft_isalpha(int c)
    {
    	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    		return (1);
    	return (0);
    }
    
    ```
    
- **isascii** (Verifica si el valor de `c` está en el rango válido de la tabla ASCII (0 a 127).)
    
    ```c
    #include "libft.h"
    
    int	ft_isascii(int c)
    {
    	if (c >= 0 && c <= 127)
    		return (1);
    	return (0);
    }
    ```
    
- **isdigit** (Comprueba si el valor de `c` está entre '0' y '9')
    
    ```c
    int	ft_isdigit(int c)
    {
    	if (c >= '0' && c <= '9')
    		return (1);
    	return (0);
    }
    ```
    
- **isprint** (Verifica si el valor de `c` está en el rango imprimible de la tabla ASCII (desde el espacio `' '` que es 32 hasta `~` que es 126)).
    
    ```c
    int ft_isprint(int c)
    {
        if (c >= 32 && c <= 126)
            return (1);
        return (0);
    }
    ```
    
- **tolower** (Si `c` está entre `'A'` y `'Z'`, se le suma 32 para convertirlo a minúscula).
    
    ```c
    int	ft_tolower(int c)
    {
    	if (c >= 'A' && c <= 'Z')
    		return (c + 32);
    	return (c);
    }
    ```
    
- **toupper** (Si `c` está entre `'a'` y `'z'`, se le resta 32 para convertirlo en mayúscula).
    
    ```c
    #include "libft.h"
    
    char	ft_adapt_toupper(unsigned int index, char c)
    {
    	if (index % 2 == 0)
    		return (ft_toupper(c));
    	return (c);
    }
    
    void	ft_adapt_toupper2(unsigned int i, char *c)
    {
    	(void)i;
    	if (*c >= 'a' && *c <= 'z')
    		*c = *c - 32;
    }
    
    int	ft_toupper(int c)
    {
    	if (c >= 'a' && c <= 'z')
    		return (c - 32);
    	return (c);
    }
    
    ```
    

**mem_ Funciones de manipulación de memoria y bzero y calloc.**

- **bzero** (Convertimos el puntero `s` a un puntero de tipo `unsigned char *` para trabajar byte a byte).
    
    (Usamos un bucle `while` para recorrer cada byte de la memoria y asignar el valor 0 hasta haber modificado `n` bytes).
    
    ```c
    
    void	ft_bzero(void *s, unsigned int n)
    {
    	unsigned int	i;
    	unsigned char	*ptr;
    
    	ptr = (unsigned char *)s;
    	i = 0;
    	while (i < n)
    	{
    		ptr[i] = 0;
    		i++;
    	}
    }
    
    ```
    
- **calloc** Reservar memoria dinámica para un número de elementos, inicializa dicha memoria a cero (requiere `malloc`)).
    - **Explicación:**
        - `total_size = count * size;`: Se calcula el tamaño total de memoria necesario multiplicando el número de elementos (`count`) por el tamaño de cada elemento (`size`).
        - `if (total_size / size != count)`: Esta condición es un chequeo para verificar que la multiplicación no haya causado un **desbordamiento**.
        
        ### ¿Qué está ocurriendo con `ptr`?
        
        1. **Asignación de memoria con `malloc(total_size)`**:
            - La función `malloc()` solicita al sistema un bloque de memoria de tamaño `total_size` bytes. Si tiene éxito, `malloc()` devuelve un **puntero** a la primera dirección de ese bloque de memoria recién asignado en el **heap**.
            - La variable `ptr` (que es un puntero) ahora contiene la **dirección de memoria** donde comienza el bloque de memoria de tamaño `total_size`.
            
            Si la asignación falla (por ejemplo, si no hay suficiente memoria disponible), `malloc()` devuelve `NULL`. Por eso se verifica con `if (!ptr)`.
            
        2. **Comprobación de asignación fallida**:
            - `if (!ptr)`: Si `ptr` es `NULL` (lo que significa que `malloc` no pudo asignar la memoria).
        3. **Uso de `ft_bzero(ptr, total_size)`**:
            - Si la asignación de memoria fue exitosa, se llama a `ft_bzero(ptr, total_size)`. Esta función pone en cero todos los bytes del bloque de memoria apuntado por `ptr`. En otras palabras, **asigna el valor `0` a cada byte de la memoria** reservada. Así, inicializa la memoria para que no contenga valores basura.
        4. **Retorno de `ptr`**:
            - Finalmente, la función devuelve `ptr`, que es el **puntero** a la memoria asignada y ahora inicializada con ceros.
        
        ### ¿Qué ocurre con `ptr` exactamente?
        
        - **Antes de `malloc()`**: `ptr` es simplemente una variable puntero, pero no apunta a una ubicación válida en la memoria.
        - **Después de `malloc()`**: Si la asignación es exitosa, `ptr` ahora contiene la dirección del primer byte de un bloque de memoria recién asignado en el heap.
        - **`ft_bzero()`**: Los datos en la dirección de memoria apuntada por `ptr` son modificados. Se llenan todos los bytes de ese bloque de memoria con ceros, pero la **dirección de memoria a la que apunta `ptr` no cambia**.
        - **Retorno**: La función retorna `ptr`, el cual sigue apuntando al mismo bloque de memoria, pero ahora inicializado a ceros.
    
    ```c
    #include "libft.h"
    
    void	*ft_calloc(size_t count, size_t size)
    {
    	void	*ptr;
    	size_t	total_size;
    
    	if (count == 0 || size == 0)
    		return (malloc(0));
    	total_size = count * size;
    	if (total_size / size != count)
    		return (NULL);
    	ptr = malloc(total_size);
    	if (!ptr)
    		return (NULL);
    	ft_bzero(ptr, total_size);
    	return (ptr);
    }
    
    ```
    
- **memchr** Busca un byte específico en un bloque de memoria.
    - **¿Para qué sirve?**
    Sirve para buscar la primera aparición de un byte en una parte de la memoria (como en un array o cadena).
    - **Funcionamiento**:
        - Busca el byte `c` en los primeros `n` bytes de la memoria apuntada por `s`.
        - Si encuentra el byte, devuelve un puntero a esa posición.
    - **Explicación detallada:**
        
        ### ¿Cómo funciona la búsqueda en la memoria?
        
        - La función recorre **byte por byte** el bloque de memoria. Es decir, revisa cada posición (cada dirección de memoria) para ver si contiene el valor de `c`.
        - **Si lo encuentra**, devuelve un **puntero a esa posición en la memoria**, es decir, te dice exactamente dónde está el byte que estás buscando dentro del bloque.
        - Ejemplo práctico
        
        Imagina que tienes un array de enteros, pero quieres buscar un byte en particular:
        
        ```c
        int arr[] = {1, 2, 3, 4};
        char *result = ft_memchr(arr, 2, sizeof(arr));
        ```
        
        Aquí, estamos buscando el **valor del byte `2`** en los primeros **16 bytes** (4 enteros de 4 bytes cada uno) de `arr`. `ft_memchr` buscará byte por byte a ver si encuentra el valor `2` en la memoria del array.
        
        ### Memoria y tamaño
        
        Cuando hablamos de "memoria" en este contexto, no estamos diciendo que la memoria esté ocupada o reservada en su totalidad. Lo que hacemos es **mirar un rango específico de direcciones de memoria** (desde la dirección `s` y por `n` bytes) y verificar su contenido, sin importar si la memoria fue asignada manualmente o es parte de una variable ya existente.
        
        - **Memoria reservada**: Cuando usas funciones como `malloc()`, estás reservando un bloque de memoria en el **heap**.
        - **Memoria no reservada**: También puedes trabajar con memoria que ya está en uso, como una variable global, local o un array.
        
        ### Resumen:
        
        - **La memoria está compuesta por bytes**, y `ft_memchr` recorre un bloque de memoria (un rango de direcciones) desde el inicio (`s`) hasta el byte número `n` para ver si alguno de esos bytes coincide con el valor `c`.
        - **No importa si esa memoria fue asignada o no**, lo importante es que la función mira el contenido de la memoria ya existente para buscar un valor específico.
        - **No cambia la memoria ni la asigna**, solo la inspecciona.
    - **`str[i] == (unsigned char)c`**:
        - Esta expresión verifica si el **byte actual** que se está inspeccionando (`str[i]`) es **igual al byte buscado** (`(unsigned char)c`).
        - Si son iguales, esto significa que hemos encontrado el byte que estábamos buscando en el bloque de memoria.
    - **`return ((void *)&str[i]);`**:
        - Si la condición anterior se cumple (es decir, encontramos el byte buscado), esta línea devuelve un puntero a la posición donde se encontró el byte.
        - `&str[i]` obtiene la dirección del byte `i` en la memoria, y el resultado es un puntero a `unsigned char`.
        - Al hacer el cast `(void *)`, convertimos ese puntero a un puntero genérico de tipo `void *`, que es el tipo de retorno de la función. Esto permite que la función sea más flexible, ya que puede ser usada con diferentes tipos de datos.
        - La razón para devolver un puntero es que permite al llamador de la función saber dónde se encontró el byte buscado en el bloque de memoria.
    
    ```c
    #include "libft.h"
    
    void	*ft_memchr(const void *s, int c, size_t n)
    {
    	size_t			i;
    	unsigned char	*str;
    
    	str = (unsigned char *)s;
    	i = 0;
    	while (i < n)
    	{
    		if (str[i] == (unsigned char)c)
    			return ((void *)&str[i]);
    		i++;
    	}
    	return (NULL);
    }
    
    ```
    
    **Ejemplo de uso**:
    Si tienes un array de caracteres (o cualquier bloque de memoria) y quieres saber si cierto carácter (como `'a'`) aparece en los primeros 10 bytes, usarías `ft_memchr`.
    
    ```c
    char str[] = "Hola Mundo";
    char *result = ft_memchr(str, 'a', 10);
    // result apuntará a la 'a' en "Hola", porque está dentro de los primeros 10 bytes.
    ```
    
- **memcmp** Compara byte por byte dos bloques de memoria.
    - **¿Para qué sirve?**
    Se usa para verificar si dos bloques de memoria (por ejemplo, dos arrays o cadenas) son iguales o si uno es mayor o menor que el otro en base a los valores de sus bytes.
    - **Funcionamiento**:
        - Toma dos bloques de memoria (`s1` y `s2`) y compara los primeros `n` bytes de ambos.
        - Si encuentra alguna diferencia en un byte, devuelve la diferencia numérica entre los valores de esos dos bytes.
        - Si todos los bytes son iguales, devuelve `0`, lo que significa que los bloques son idénticos en ese rango.
    
    ```c
    #include "libft.h"
    
    int	ft_memcmp(const void *s1, const void *s2, size_t n)
    {
    	size_t			i;
    	unsigned char	*str1;
    	unsigned char	*str2;
    
    	str1 = (unsigned char *)s1;
    	str2 = (unsigned char *)s2;
    	i = 0;
    	while (i < n)
    	{
    		if (str1[i] != str2[i])
    			return ((int)(str1[i] - str2[i]));
    		i++;
    	}
    	return (0);
    }
    ```
    
    **Ejemplo de uso**:
    Imagina que tienes dos arrays de bytes y quieres saber si son iguales en los primeros 5 bytes.
    
    ```c
    char str1[] = "abcdef";
    char str2[] = "abcxef";
    int result = ft_memcmp(str1, str2, 4);
    // result será 0 porque los primeros 4 caracteres son iguales ('a', 'b', 'c', 'd').
    ```
    
- **memcpy** Copia un bloque de memoria a otro bloque.
    - **¿Para qué sirve?**
    Se utiliza para copiar `n` bytes de un bloque de memoria (`src`) a otro bloque (`dst`), de manera rápida y segura.
    - **Funcionamiento**:
        - Toma dos punteros (`dst` y `src`) y copia exactamente `n` bytes desde `src` a `dst`.
        - Se asegura de no alterar el contenido original de `src` y garantiza que los bytes se copien correctamente a `dst`.
    
    ```c
    #include "libft.h"
    
    void	*ft_memcpy(void *dst, const void *src, unsigned int n)
    {
    	unsigned int		i;
    	unsigned char		*d;
    	const unsigned char	*s;
    
    	if (!dst && !src)
    		return (NULL);
    	d = (unsigned char *)dst;
    	s = (const unsigned char *)src;
    	i = 0;
    	while (i < n)
    	{
    		d[i] = s[i];
    		i++;
    	}
    	return (dst);
    }
    
    ```
    
    **Ejemplo de uso**:
    Si tienes un array y quieres copiar parte de él a otro lugar en memoria, usarías `ft_memcpy`.
    
    ```c
    char src[] = "Hello, World!";
    char dst[20];
    
    ft_memcpy(dst, src, 13);
    // Ahora dst contiene "Hello, World!".
    ```
    
- **memmove** Copia un bloque de memoria a otro bloque de memoria, con la particularidad de que funciona correctamente cuando las dos áreas de memoria se solapan (Desglosamiento).
    - **¿Para qué sirve?**`ft_memmove` se utiliza para copiar un bloque de memoria a otro lugar en memoria, incluso si las áreas de origen y destino se superponen.
    - **Funcionamiento**:
        - Si el destino está antes del origen en memoria, usa una función auxiliar `copy_forward` para copiar los bytes de forma ascendente (de menor a mayor).
        - Si el destino está después del origen (y se superponen), usa `copy_backward` para copiar los bytes de forma descendente, evitando que el contenido se sobrescriba antes de ser copiado.
        - En ambos casos, el contenido se copia correctamente, sin corromper los datos si hay solapamiento entre el destino y el origen.
    
    ```c
    #include "libft.h"
    
    void	copy_forward(unsigned char *dst, const unsigned char *source, size_t n)
    {
    	size_t	i;
    
    	i = 0;
    	while (i < n)
    	{
    		dst[i] = source[i];
    		i++;
    	}
    }
    
    void	copy_backward(unsigned char *dst, const unsigned char *source, size_t n)
    {
    	size_t	i;
    
    	i = n;
    	while (i > 0)
    	{
    		i--;
    		dst[i] = source[i];
    	}
    }
    
    void	*ft_memmove(void *dest, const void *src, size_t n)
    {
    	unsigned char		*dst;
    	const unsigned char	*source;
    
    	dst = (unsigned char *)dest;
    	source = (const unsigned char *)src;
    	if (dst == source || n == 0)
    		return (dest);
    	if (dst < source)
    		copy_forward(dst, source, n);
    	else
    		copy_backward(dst, source, n);
    	return (dest);
    }
    
    ```
    
    **Ejemplo de uso**:
    Si tienes un array y necesitas mover un bloque de memoria dentro del mismo array sin corromper los datos.
    
    ```c
    char src[] = "Hola Mundo";
    
    ft_memmove(src + 5, src, 5);
    // Ahora el contenido de src será "Hola Holao", ya que movió "Hola " hacia adelante.
    
    ```
    
- **memset** Llena un bloque de memoria con un valor específico, byte por byte.
    - **¿Para qué sirve?**`ft_memset` se utiliza para inicializar o rellenar una región de memoria con un valor específico. Es útil para, por ejemplo, establecer todos los bytes de un array a cero o a cualquier otro valor.
    - **Funcionamiento**:
        - Toma un puntero a un bloque de memoria (`b`) y lo convierte a `unsigned char *` para manipularlo byte por byte.
        - Luego, recorre los primeros `len` bytes de ese bloque y asigna el valor de `c` (convertido a `unsigned char`) a cada byte.
        - Finalmente, devuelve el puntero original, permitiendo que el bloque de memoria esté accesible.
    
    ```c
    void	*ft_memset(void *b, int c, unsigned int len)
    {
    	unsigned int	i;
    	unsigned char	*ptr;
    
    	ptr = (unsigned char *)b;
    	i = 0;
    	while (i < len)
    	{
    		ptr[i] = (unsigned char)c;
    		i++;
    	}
    	return (b);
    }
    
    ```
    
    **Ejemplo de uso**:
    Si quieres rellenar un array de 10 bytes con el valor 0.
    
    ```c
    char buffer[10];
    
    ft_memset(buffer, 0, 10);
    // Ahora todos los bytes de buffer estarán inicializados a 0.
    
    ```
    

**str_ Funciones de manipulación de cadenas (strlen, strchr, etc.):**

- **atoi** - Convierte una cadena en un entero.
    
    ```c
    #include "libft.h"
    
    int	ft_is_space(char c)
    {
    	if (c == ' ' || (c >= 9 && c <= 13))
    		return (1);
    	return (0);
    }
    
    int	ft_check_sign(const char *str, int *i)
    {
    	int	sign;
    
    	sign = 1;
    	if (str[*i] == '-' || str[*i] == '+')
    	{
    		if (str[*i] == '-')
    			sign = -1;
    		(*i)++;
    	}
    	return (sign);
    }
    
    int	ft_overflow(int result, int digit, int sign)
    {
    	if (result > (INT_MAX / 10) || (result == INT_MAX / 10 && digit > 7))
    	{
    		if (sign == 1)
    			return (INT_MAX);
    		else
    			return (INT_MIN);
    	}
    	return (0);
    }
    
    int	ft_atoi(const char *str)
    {
    	int	i;
    	int	sign;
    	int	result;
    	int	overflow_check;
    
    	i = 0;
    	result = 0;
    	while (ft_is_space(str[i]))
    		i++;
    	sign = ft_check_sign(str, &i);
    	while (str[i] >= '0' && str[i] <= '9')
    	{
    		overflow_check = ft_overflow(result, str[i] - '0', sign);
    		if (overflow_check)
    			return (overflow_check);
    		result = result * 10 + (str[i] - '0');
    		i++;
    	}
    	return (result * sign);
    }
    
    ```
    
- **strrchr** El prototipo de la función es `char *ft_strrchr(const char *s, int c)`, donde:
    
    `s`: La cadena en la que se busca el carácter.
    
    `c`: El carácter que se busca.
    
    Última aparición del carácter:
    
    Utilizo un puntero `last_occurrence` para almacenar la dirección de la última aparición del carácter `c` en la cadena.
    
    Recorro toda la cadena con un bucle `while` y cada vez que encuentro el carácter, actualizo el puntero `last_occurrence`.
    
    Si `c` es `'\0'`, devuelve un puntero al final de la cadena, como es habitual en `strrchr`.
    
    **Si no se encuentra el carácter:** Si el carácter `c` no aparece en la cadena, la función devuelve `NULL`.
    
    ```c
    #include "libft.h"
    
    char	*ft_strrchr(const char *s, int c)
    {
    	size_t	i;
    	char	*last_occurrence;
    	char	target;
    
    	target = (char)c;
    	i = 0;
    	last_occurrence = NULL;
    	while (s[i] != '\0')
    	{
    		if (s[i] == target)
    			last_occurrence = (char *)&s[i];
    		i++;
    	}
    	if (target == '\0')
    		return ((char *)&s[i]);
    	return (last_occurrence);
    }
    ```
    
- **strlcat** - Concatenación segura de cadenas.
    
    ```c
    #include "libft.h"
    
    size_t	ft_strlcat(char *dest, const char *src, size_t size)
    {
    	size_t	dest_len;
    	size_t	src_len;
    	size_t	i;
    
    	dest_len = ft_strlen(dest);
    	src_len = ft_strlen(src);
    	if (size <= dest_len)
    		return (size + src_len);
    	i = 0;
    	while (src[i] != '\0' && (dest_len + i) < (size - 1))
    	{
    		dest[dest_len + i] = src[i];
    		i++;
    	}
    	dest[dest_len + i] = '\0';
    	return (dest_len + src_len);
    }
    
    ```
    
- **strlcpy** - Copia segura de cadenas.
    
    ```c
    #include <stdio.h>
    
    size_t	ft_strlcpy(char *dest, const char *src, size_t size)
    {
    	size_t	i;
    	size_t	src_len;
    
    	src_len = 0;
    	while (src[src_len] != '\0')
    	{
    		src_len++;
    	}
    	if (size > 0)
    	{
    		i = 0;
    		while (i < size - 1 && src[i] != '\0')
    		{
    			dest[i] = src[i];
    			i++;
    		}
    		dest[i] = '\0';
    	}
    	return (src_len);
    }
    ```
    
- **strlen** (Calcula la longitud de la string).
    
    ```c
    #include "libft.h"
    
    size_t	ft_strlen(const char *str)
    {
    	size_t	len;
    
    	len = 0;
    	while (str[len] != '\0')
    		len++;
    	return (len);
    }
    
    ```
    
- **strncmp** Comparación de cadenas:
    
    Recorre ambas cadenas caracter por caracter usando un bucle `while`, hasta que se hayan comparado los primeros `n` caracteres o hasta que una de las cadenas termine (`\0`).
    
    Si los caracteres en las posiciones actuales de `s1` y `s2` son diferentes, devuelve la diferencia entre ellos, convertidos a `unsigned char` para evitar errores con caracteres negativos.
    
    Si las dos cadenas son iguales hasta el final o dentro de los primeros `n` caracteres, la función devuelve `0`.
    
    ```c
    #include "libft.h"
    
    int	ft_strncmp(const char *s1, const char *s2, size_t n)
    {
    	size_t	i;
    
    	i = 0;
    	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
    	{
    		if (s1[i] != s2[i])
    			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    		i++;
    	}
    	return (0);
    }
    ```
    
- **strnstr** Buscar un subcadena dentro de una cadena.
    
    `haystack`: La cadena en la que se busca.`needle`: La subcadena que se busca.
    
    `len`: El número máximo de caracteres en `haystack` a examinar.
    
    Caso especial para `needle` vacío:
    
    Si `needle` es una cadena vacía, la función devuelve `haystack`, ya que cualquier cadena contiene la subcadena vacía.
    
    Búsqueda de la subcadena:
    
    Se usa un bucle `while` para recorrer `haystack`.
    
    Dentro de ese bucle, se usa otro bucle `while` para comparar caracteres de `needle` con los caracteres actuales en `haystack`.
    
    Si se encuentra una coincidencia completa de `needle` dentro de los primeros `len` caracteres de `haystack`, se devuelve un puntero a la primera aparición de `needle` en `haystack`.
    
    Si `needle` no se encuentra, se devuelve `NULL`.
    
    ```c
    #include "libft.h"
    
    char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
    {
    	size_t	i;
    	size_t	j;
    
    	if (*needle == '\0')
    		return ((char *)haystack);
    	i = 0;
    	while (haystack[i] != '\0' && i < len)
    	{
    		j = 0;
    		while (needle[j] != '\0' && (i + j) < len
    			&& haystack[i + j] == needle[j])
    			j++;
    		if (needle[j] == '\0')
    			return ((char *)&haystack[i]);
    		i++;
    	}
    	return (NULL);
    }
    
    ```
    
- **strchr B**usca la primera aparición de un carácter dado en una cadena y devuelve un puntero a esa posición o `NULL` si no se encuentra.
    
    **Explicación detallada:**
    
    - `target = (char)c;`: Convierte el entero `c` en un carácter, que será el valor que se buscará en la cadena.
    - `while (s[i] != '\0')`: Recorre la cadena `s` carácter por carácter hasta que se llega al final (`\0`).
    - `if (s[i] == target)`: Si el carácter en la posición actual coincide con el carácter buscado, retorna un puntero a esa posición en la cadena.
    - Si no encuentra el carácter en el bucle, verifica si el carácter buscado es el carácter nulo (`'\0'`), y en ese caso, devuelve un puntero al final de la cadena.
    - Si no encuentra el carácter y no es el carácter nulo, devuelve `NULL`.
    
    `s`: La cadena en la que se busca el carácter.
    
    `c`: El carácter que se busca.).
    
    Utilizo un puntero `last_occurrence` para almacenar la dirección de la última aparición del carácter `c` en la cadena.
    
    Recorro toda la cadena con un bucle `while` y cada vez que encuentro el carácter, actualizo el puntero `last_occurrence`.
    
    Si `c` es `'\0'`, devuelve un puntero al final de la cadena, como es habitual en `strrchr`.
    
    **Si no se encuentra el carácter:** Si el carácter `c` no aparece en la cadena, la función devuelve `NULL`.
    
    ```c
    #include "libft.h"
    
    char	*ft_strchr(const char *s, int c)
    {
    	size_t	i;
    	char	target;
    
    	target = (char)c;
    	i = 0;
    	while (s[i] != '\0')
    	{
    		if (s[i] == target)
    			return ((char *)&s[i]);
    		i++;
    	}
    	if (target == '\0')
    		return ((char *)&s[i]);
    	return (NULL);
    }
    ```
    
    - Ejemplo de main en ft_strchr:
        
        ```c
        int main(void)
        {
            const char *str = "Hola, mundo mundan!";
            char c = 'm';
            char *result;
        
            result = ft_strchr(str, c);
            if (result != NULL)
                printf("El carácter '%c' fue encontrado en: %s\n", c, result);
            else
                printf("El carácter '%c' no fue encontrado en la cadena.\n", c);
        
            // Probar con el carácter nulo '\0'
            result = ft_strchr(str, '\0');
            if (result != NULL)
                printf("El carácter nulo fue encontrado al final de la cadena: %s\n", result);
        
            return 0;
        }
        ```
        
- **strdup** - Duplica una cadena (requiere `malloc`).
    
    ```c
    #include "libft.h"
    #include <stdlib.h>
    
    char	*ft_strdup(const char *s1)
    {
    	char	*dup;
    	size_t	len;
    	size_t	i;
    
    	len = ft_strlen(s1);  // Calcula la longitud de la cadena original
    	dup = (char *)malloc((len + 1) * sizeof(char));  // Reserva memoria para la nueva cadena
    	if (!dup)
    		return (NULL);
    	i = 0;
    	while (i < len)
    	{
    		dup[i] = s1[i];
    		i++;
    	}
    	dup[i] = '\0';  // Asegúrate de agregar el carácter nulo al final
    	return (dup);
    }
    
    ```
    

## ***Parte 2 - Funciones adicionales***

En esta segunda parte, deberás desarrollar un conjunto de funciones que, o no son de
la librería libc, o lo son pero de una forma distinta.

- **substr** Extrae una subcadena desde un índice específico de una cadena dada, con una longitud máxima. Devuelve la subcadena recién creada o `NULL` si falla la reserva de memoria.
    
    ```jsx
    #include "libft.h"
    
    static size_t	ft_get_substr_len(char const *s, unsigned int start, size_t len)
    {
    	unsigned int	s_len;
    
    	s_len = ft_strlen(s);
    	if (start >= s_len)
    		return (0);
    	if (len > s_len - start)
    		return (s_len - start);
    	return (len);
    }
    
    static char	*ft_allocate_substr(size_t len)
    {
    	char	*substr;
    
    	substr = (char *)malloc(sizeof(char) * (len + 1));
    	if (substr)
    		substr[0] = '\0';
    	return (substr);
    }
    
    char	*ft_substr(char const *s, unsigned int start, size_t len)
    {
    	char		*substr;
    	size_t		i;
    
    	if (!s)
    		return (NULL);
    	len = ft_get_substr_len(s, start, len);
    	substr = ft_allocate_substr(len);
    	if (!substr)
    		return (NULL);
    	i = 0;
    	while (i < len)
    	{
    		substr[i] = s[start + i];
    		i++;
    	}
    	substr[i] = '\0';
    	return (substr);
    }
    
    ```
    
- **strjoin** Concatena dos cadenas (`s1` y `s2`) en una nueva cadena, reservando memoria para ello. Devuelve la nueva cadena o `NULL` si la reserva de memoria falla.
    
    ```jsx
    #include "libft.h"
    
    char	*ft_strjoin(char const *s1, char const *s2)
    {
    	char			*new_str;
    	unsigned int	total_len;
    	unsigned int	i;
    	unsigned int	j;
    
    	if (!s1 || !s2)
    		return (NULL);
    	total_len = ft_strlen(s1) + ft_strlen(s2);
    	new_str = (char *)malloc(sizeof(char) * (total_len + 1));
    	if (!new_str)
    		return (NULL);
    	i = 0;
    	while (s1[i])
    	{
    		new_str[i] = s1[i];
    		i++;
    	}
    	j = 0;
    	while (s2[j])
    	{
    		new_str[i + j] = s2[j];
    		j++;
    	}
    	new_str[i + j] = '\0';
    	return (new_str);
    }
    ```
    
- **strtrim** Recorta los caracteres del principio y el final de una cadena según un conjunto de caracteres dados. Devuelve una nueva cadena sin los caracteres de `set` en los extremos, o `NULL` si falla la reserva de memoria.
    
    ```jsx
    #include "libft.h"
    
    static int	ft_is_in_set(char c, const char *set)
    {
    	unsigned int	i;
    
    	i = 0;
    	while (set[i])
    	{
    		if (set[i] == c)
    			return (1);
    		i++;
    	}
    	return (0);
    }
    
    char	*ft_strtrim(char const *s1, char const *set)
    {
    	char			*trimmed;
    	unsigned int	start;
    	unsigned int	end;
    	unsigned int	i;
    
    	if (!s1 || !set)
    		return (NULL);
    	start = 0;
    	end = ft_strlen(s1);
    	while (s1[start] && ft_is_in_set(s1[start], set))
    		start++;
    	while (end > start && ft_is_in_set(s1[end - 1], set))
    		end--;
    	trimmed = (char *)malloc(sizeof(char) * (end - start + 1));
    	if (!trimmed)
    		return (NULL);
    	i = 0;
    	while (start < end)
    	{
    		trimmed[i] = s1[start];
    		start++;
    		i++;
    	}
    	trimmed[i] = '\0';
    	return (trimmed);
    }
    
    ```
    
- **split:** Esta es la función principal que se utiliza para dividir una cadena `s` en subcadenas utilizando el carácter separador `c`. Llama a las funciones auxiliares para contar palabras, reservar memoria, y copiar las subcadenas.
    - **Uso**: Se invoca directamente cuando se necesita dividir una cadena en palabras, retornando un arreglo de cadenas resultante o `NULL` si falla la memoria.
    
    ### Funciones:
    
    1. `ft_count_words **(Contar palabras):**`
        - **Descripción**: Esta función cuenta el número de palabras en una cadena `s`, donde las palabras están separadas por un carácter `c`.
        - **Uso**: Se utiliza para determinar cuántas subcadenas (palabras) se deben crear en la memoria.
    2. `ft_malloc_strs (**ft_reservar_memoria_subcadenas)**:`
        - **Descripción**: Esta función reserva memoria para las subcadenas en un arreglo de cadenas (`strs`). La cantidad de memoria reservada está determinada por el número de palabras contadas en `ft_contar_palabras`.
        - **Uso**: Se invoca para asignar memoria para cada subcadena que se extraerá de la cadena original.
    3. `ft_cpy_strs (**ft_copiar_subcadenas)**:`
        - **Descripción**: Esta función copia las subcadenas de la cadena original `s` al arreglo de cadenas `strs`, terminando cada subcadena con un carácter nulo (`'\0'`).
        - **Uso**: Se utiliza para llenar el arreglo de subcadenas después de haber reservado la memoria correspondiente.
    4. `ft_mem_error (**ft_memoria_error)**:`
        - **Descripción**: Esta función libera la memoria que se ha reservado en caso de que ocurra un error en la asignación de memoria durante el proceso de creación de subcadenas.
        - **Uso**: Se llama para liberar la memoria y evitar fugas cuando no se puede completar la creación de subcadenas.
    
    ```c
    #include "libft.h"
    
    /*
    	DESCRIPTION :
    	The function ft_split allocates and copies an array of strings by 
    	splitting the given string s using the given separator c.
    
    	RETURN VALUE :
    	An array of strings resulting from the split. NULL if the memory
    	allocation fails.
    */
    
    // Cuenta cuántas palabras hay en la cadena 's', separadas por el carácter 'c'.
    static int	ft_count_words(const char *s, char c)
    {
    	int	words;
    	int	i;
    
    	words = 0;
    	i = 0;
    	while (s[i])
    	{
    		// Si encontramos un carácter diferente de 'c' y estamos al principio o después de un 'c', contamos una palabra.
    		if ((i == 0 && s[i] != c) || (i > 0 && s[i] != c && s[i - 1] == c))
    			words++;
    		i++;
    	}
    	return (words);
    }
    
    // Asigna memoria para cada palabra
    static char	**ft_malloc_strs(char **strs, const char *s, char c)
    {
    	int	len;
    	int	i;
    	int	x;
    
    	len = 0;
    	i = 0;
    	x = 0;
    	while (s[i])
    	{
    		// Contamos la longitud de cada palabra.
    		if (s[i] != c)
    			len++;
    		// Si llegamos al final de una palabra, asignamos memoria.
    		if ((s[i] == c && len > 0) || (s[i + 1] == '\0' && len > 0))
    		{
    			strs[x] = malloc(sizeof(char) * (len + 1)); // +1 para '\0'
    			if (!strs[x])
    				return (NULL);
    			len = 0;
    			x++;
    		}
    		i++;
    	}
    	return (strs);
    }
    
    // Copia cada palabra en el array
    static char	**ft_cpy_strs(char **strs, const char *s, char c)
    {
    	int	i;
    	int	x;
    	int	y;
    
    	i = 0;
    	x = 0;
    	y = 0;
    	while (s[i])
    	{
    		// Si no es el carácter separador, lo copiamos en la palabra actual.
    		if (s[i] != c)
    			strs[x][y++] = s[i];
    		// Si llegamos al final de una palabra, añadimos '\0' para terminarla.
    		if ((s[i] == c && y > 0) || (s[i + 1] == '\0' && y > 0))
    		{
    			strs[x][y] = '\0';
    			x++;
    			y = 0;
    		}
    		i++;
    	}
    	return (strs);
    }
    
    // Manejo de error de memoria
    static char	**ft_mem_error(char **strs)
    {
    	int	i;
    
    	i = 0;
    	while (strs[i])
    	{
    		free(strs[i]);
    		strs[i] = NULL;
    		i++;
    	}
    	free(strs);
    	return (NULL);
    }
    
    // Función principal ft_split
    char	**ft_split(char const *s, char c)
    {
    	char	**strs;
    	int		wordcount;
    
    	if (!s)
    		return (NULL);
    	wordcount = ft_count_words(s, c);
    	strs = malloc(sizeof(*strs) * (wordcount + 1));
    	if (!strs)
    		return (NULL);
    	if (ft_malloc_strs(strs, s, c))
    	{
    		ft_cpy_strs(strs, s, c);
    		strs[wordcount] = NULL;
    	}
    	else
    		strs = ft_mem_error(strs);
    	return (strs);
    }
    
    // Prueba del ft_split
    int main()
    {
        char *str = "; holaaaaa ;;; ho;la !!!34243";
        char **str2 = ft_split(str, ';');
        int i = 0;
    
        if (!str2)
        {
            printf("Error en la asignación de memoria.\n");
            return (1);
        }
        
        // Recorrer el array de strings y mostrarlos
        while (str2[i])
        {
            printf("str2[%d]: %s\n", i, str2[i]);
            free(str2[i]); // Liberar cada string.
            i++;
        }
        
        free(str2); // Liberar el array de punteros.
    
        return 0;
    }
    
    ```
    
- **itoa** Convierte un número entero a una cadena. Maneja números negativos y positivos, reservando la memoria necesaria para el resultado. Devuelve la cadena correspondiente o `NULL` si falla la reserva de memoria.
    
    ```jsx
    #include "libft.h"
    
    static int	ft_num_len(int n)
    {
    	int		len;
    
    	len = 0;
    	if (n <= 0)
    		len = 1;
    	while (n)
    	{
    		n /= 10;
    		len++;
    	}
    	return (len);
    }
    
    char	*ft_itoa(int n)
    {
    	char			*str;
    	int				len;
    	unsigned int	num;
    
    	len = ft_num_len(n);
    	str = (char *)malloc(sizeof(char) * (len + 1));
    	if (!str)
    		return (NULL);
    	str[len] = '\0';
    	if (n < 0)
    		num = -n;
    	else
    		num = n;
    	if (n < 0)
    		str[0] = '-';
    	if (num == 0)
    		str[0] = '0';
    	while (num > 0)
    	{
    		str[--len] = (num % 10) + '0';
    		num /= 10;
    	}
    	return (str);
    }
    ```
    
- **strmapi** Aplica una función dada a cada carácter de una cadena, pasando el índice como argumento. Genera una nueva cadena con los resultados, reservando memoria para ello, o devuelve `NULL` si falla la reserva.
    
    ```jsx
    
    #include "libft.h"
    
    char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
    {
    	char			*new_str;
    	unsigned int	i;
    
    	if (!s || !f)
    		return (NULL);
    	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    	if (!new_str)
    		return (NULL);
    	i = 0;
    	while (s[i])
    	{
    		new_str[i] = f(i, s[i]);
    		i++;
    	}
    	new_str[i] = '\0';
    	return (new_str);
    }
    
    ```
    
- **striteri** Itera sobre cada carácter de una cadena, aplicando una función que recibe el índice y la dirección del carácter. No devuelve nada y permite modificar los caracteres directamente.
    
    ```jsx
    void	ft_striteri(char *s, void (*f)(unsigned int, char*))
    {
    	unsigned int	i;
    
    	if (!s || !f)
    		return ;
    	i = 0;
    	while (s[i])
    	{
    		f(i, &s[i]);
    		i++;
    	}
    }
    
    ```
    
- **putchar_fd** Envía un carácter al file descriptor especificado usando la función `write`.
    
    ```jsx
    #include <unistd.h>
    
    void	ft_putchar_fd(char c, int fd)
    {
    	write(fd, &c, 1);
    }
    
    ```
    
- **putstr_fd** Envía una cadena al file descriptor especificado, utilizando la función `write`. Si la cadena es nula, no realiza ninguna acción.
    
    ```jsx
    #include "libft.h"
    
    void	ft_putstr_fd(char *s, int fd)
    {
    	if (!s)
    		return ;
    	while (*s)
    	{
    		write(fd, s, 1);
    		s++;
    	}
    }
    
    ```
    
- **putendl_fd** Envía una cadena al file descriptor especificado, seguida de un salto de línea. Si la cadena es nula, no realiza ninguna acción.
    
    ```jsx
    #include "libft.h"
    
    void ft_putendl_fd(char *s, int fd)
    {
        if (!s)
            return;
        while (*s)
        {
            write(fd, s, 1);
            s++;
        }
        write(fd, "\n", 1);
    }
    
    ```
    
- **putnbr_fd** Envía un número entero a un file descriptor especificado, manejando tanto números positivos como negativos. Utiliza una función recursiva para descomponer y escribir el número en el orden correcto.
    
    ```jsx
    #include "libft.h"
    
    static void	ft_putnbr_recursive(int n, int fd)
    {
    	char	digit;
    
    	if (n < 0)
    	{
    		write(fd, "-", 1);
    		n = -n;
    	}
    	if (n >= 10)
    	{
    		ft_putnbr_recursive(n / 10, fd);
    	}
    	digit = '0' + (n % 10);
    	write(fd, &digit, 1);
    }
    
    void	ft_putnbr_fd(int n, int fd)
    {
    	if (n == -2147483648)
    	{
    		write(fd, "-2147483648", 11);
    		return ;
    	}
    	ft_putnbr_recursive(n, fd);
    }
    
    ```
    

## ***Parte 3 - Parte bonus***

- **ft_lstnew_bonus** - Crea un nuevo nodo para una lista enlazada, inicializando su contenido con el valor proporcionado y su puntero `next` a `NULL`. Si falla la reserva de memoria, devuelve `NULL`.
    
    ```jsx
    #include "libft.h"
    
    t_list	*ft_lstnew(void *content)
    {
    	t_list	*new_node;
    
    	new_node = (t_list *)malloc(sizeof(t_list));
    	if (!new_node)
    		return (NULL);
    	new_node->content = content;
    	new_node->next = NULL;
    	return (new_node);
    }
    
    ```
    
    - **main** del **ft_lstnew_bonus.**
        
        ```c
        #include <stdio.h>
        #include <stdlib.h>
        
        // Estructura del nodo de la lista enlazada
        typedef struct s_list
        {
            void            *content;
            struct s_list   *next;
        } t_list;
        
        // Declaración de la función ft_lstnew
        t_list	*ft_lstnew(void *content)
        {
        	t_list	*new_node;
        
        	new_node = (t_list *)malloc(sizeof(t_list));
        	if (!new_node)
        		return (NULL);
        	new_node->content = content;
        	new_node->next = NULL;
        	return (new_node);
        }
        
        int main(void)
        {
            // Creamos un nodo con el contenido de una cadena
            char *content = "Hola, soy un nodo";
            t_list *node = ft_lstnew(content);
        
            // Verificamos si el nodo fue creado correctamente
            if (node)
            {
                printf("Nodo creado:\n");
                printf("Contenido: %s\n", (char *)node->content); // Imprimimos el contenido del nodo
                printf("Puntero al siguiente nodo: %p\n", node->next); // Debería ser NULL
            }
            else
            {
                printf("Error en la creación del nodo.\n");
            }
        
            // Liberamos la memoria del nodo creado
            free(node);
        
            return 0;
        }
        ```
        
- **ft_lstadd_front_bonus** - Añade un nuevo nodo al principio de una lista enlazada. El nuevo nodo se convierte en la cabeza de la lista, apuntando al nodo que era la cabeza anterior.
    
    ```jsx
    #include "libft.h"
    
    void	ft_lstadd_front(t_list **lst, t_list *new)
    {
    	if (lst && new)
    	{
    		new->next = *lst;
    		*lst = new;
    	}
    }
    
    ```
    
- **ft_lstadd_back_bonus** - Añade un nuevo nodo al final de una lista enlazada. Si la lista está vacía, el nuevo nodo se convierte en la cabeza. Si no, busca el último nodo y lo enlaza al nuevo nodo.
    
    ```jsx
    #include "libft.h"
    
    void	ft_lstadd_back(t_list **lst, t_list *new)
    {
    	t_list	*last_node;
    
    	if (!lst || !new)
    		return ;
    	if (*lst == NULL)
    	{
    		*lst = new;
    		return ;
    	}
    	last_node = ft_lstlast(*lst);
    	last_node->next = new;
    }
    ```
    
- **ft_lstsize_bonus** - Calcula y devuelve el número de nodos en una lista enlazada. Recorre la lista contando cada nodo hasta llegar al final.
    
    ```jsx
    #include "libft.h"
    
    int	ft_lstsize(t_list *lst)
    {
    	int	count;
    
    	count = 0;
    	while (lst)
    	{
    		count++;
    		lst = lst->next;
    	}
    	return (count);
    }
    
    ```
    
- **ft_lstlast_bonus** - Devuelve el último nodo de una lista enlazada. Recorre la lista hasta encontrar el nodo cuyo puntero `next` es `NULL`. Si la lista está vacía, devuelve `NULL`.
    
    ```jsx
    #include "libft.h"
    
    t_list	*ft_lstlast(t_list *lst)
    {
    	if (!lst)
    		return (NULL);
    	while (lst->next)
    		lst = lst->next;
    	return (lst);
    }
    
    ```
    
- **ft_lstdelone_bonus** - Elimina un nodo de la lista enlazada, liberando su contenido y la memoria del nodo. Se necesita una función `del` para gestionar la eliminación del contenido del nodo.
    
    ```jsx
    #include "libft.h"
    
    void	ft_lstdelone(t_list *lst, void (*del)(void*))
    {
    	if (lst && del)
    	{
    		del(lst->content);
    		free(lst);
    	}
    }
    
    ```
    
- **ft_lstclear_bonus** - Elimina todos los nodos de una lista enlazada. Utiliza una función `del` para liberar el contenido de cada nodo y luego libera la memoria del nodo. Al final, establece el puntero de la cabeza de la lista a `NULL`.
    
    ```jsx
    #include "libft.h"
    
    void	ft_lstclear(t_list **lst, void (*del)(void*))
    {
    	t_list	*temp;
    
    	if (!lst || !del)
    		return;
    	while (*lst)
    	{
    		temp = (*lst)->next;
    		ft_lstdelone(*lst, del);
    		*lst = temp;
    	}
    	*lst = NULL;
    }
    
    ```
    
- **ft_lstiter_bonus** - Itera sobre cada nodo de una lista enlazada y aplica una función `f` al contenido de cada nodo. No modifica la estructura de la lista, solo aplica la función a cada elemento.
    
    ```jsx
    #include "libft.h"
    
    void	ft_lstiter(t_list *lst, void (*f)(void*))
    {
    	if (!lst || !f)
    		return;
    	while (lst)
    	{
    		f(lst->content);
    		lst = lst->next;
    	}
    }
    
    ```
    
- **ft_lstmap_bonus** - Crea una nueva lista enlazada aplicando una función `f` a cada contenido de la lista original. Si se produce un error en la creación de un nuevo nodo, libera la nueva lista creada hasta ese momento utilizando una función `del`. Si la lista original está vacía, devuelve `NULL`.
    
    ```jsx
    #include "libft.h"
    
    t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
    {
    	t_list	*new_list;
    	t_list	*new_node;
    	void	*content;
    
    	new_list = NULL;
    	if (!lst || !f)
    		return (NULL);
    	while (lst)
    	{
    		content = f(lst->content);
    		new_node = ft_lstnew(content);
    		if (!new_node)
    		{
    			ft_lstclear(&new_list, del);
    			return (NULL);
    		}
    		ft_lstadd_back(&new_list, new_node);
    		lst = lst->next;
    	}
    	return (new_list);
    }
    
    ```
    
    - **main** del **ft_lstmap_bonus**:
        
        ```jsx
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h> 
        
        // Estructura del nodo de la lista enlazada
        typedef struct s_list
        {
            void            *content;
            struct s_list   *next;
        } t_list;
        
        // Función para crear un nuevo nodo
        t_list	*ft_lstnew(void *content)
        {
        	t_list	*new_node;
        
        	new_node = (t_list *)malloc(sizeof(t_list));
        	if (!new_node)
        		return (NULL);
        	new_node->content = content;
        	new_node->next = NULL;
        	return (new_node);
        }
        
        // Función para eliminar un nodo
        void	ft_lstdelone(t_list *lst, void (*del)(void*))
        {
        	if (lst && del)
        	{
        		del(lst->content);
        		free(lst);
        	}
        }
        
        // Función para encontrar el último nodo de la lista
        t_list	*ft_lstlast(t_list *lst)
        {
        	if (!lst)
        		return (NULL);
        	while (lst->next)
        		lst = lst->next;
        	return (lst);
        }
        
        // Función para limpiar la lista
        void	ft_lstclear(t_list **lst, void (*del)(void*))
        {
        	t_list	*temp;
        
        	if (!lst || !del)
        		return ;
        	while (*lst)
        	{
        		temp = (*lst)->next;
        		ft_lstdelone(*lst, del);
        		*lst = temp;
        	}
        	*lst = NULL;
        }
        
        // Función para añadir un nodo al final de la lista
        void	ft_lstadd_back(t_list **lst, t_list *new)
        {
        	t_list	*last_node;
        
        	if (!lst || !new)
        		return ;
        	if (*lst == NULL)
        	{
        		*lst = new;
        		return ;
        	}
        	last_node = ft_lstlast(*lst);
        	last_node->next = new;
        }
        
        // Función para mapear la lista
        t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
        {
        	t_list	*new_list;
        	t_list	*new_node;
        	void	*content;
        
        	new_list = NULL;
        	if (!lst || !f)
        		return (NULL);
        	while (lst)
        	{
        		content = f(lst->content);
        		new_node = ft_lstnew(content);
        		if (!new_node)
        		{
        			del(content);
        			ft_lstclear(&new_list, del);
        			return (NULL);
        		}
        		ft_lstadd_back(&new_list, new_node);
        		lst = lst->next;
        	}
        	return (new_list);
        }
        
        // Función que transforma el contenido a mayúsculas
        void	*content_uppercase(void *content)
        {
            char *str = (char *)content;
            for (int i = 0; str[i]; i++)
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                    str[i] -= 32; // Convierte a mayúsculas
            }
            return (void *)str;
        }
        
        // Función que elimina el contenido
        void	content_del(void *content)
        {
            free(content);
        }
        
        // Función para imprimir la lista enlazada
        void	print_list(t_list *lst)
        {
            while (lst)
            {
                printf("%s -> ", (char *)lst->content);
                lst = lst->next;
            }
            printf("NULL\n");
        }
        
        int main(void)
        {
            // Crear nodos de la lista original
            t_list *lst1 = ft_lstnew(strdup("hola"));
            t_list *lst2 = ft_lstnew(strdup("mundo"));
            t_list *lst3 = ft_lstnew(strdup("programando"));
        
            // Conectar los nodos
            lst1->next = lst2;
            lst2->next = lst3;
        
            // Imprimir lista original
            printf("Lista original:\n");
            print_list(lst1);
        
            // Aplicar ft_lstmap para transformar el contenido
            t_list *new_list = ft_lstmap(lst1, content_uppercase, content_del);
        
            // Imprimir nueva lista
            printf("\nNueva lista (contenido en mayúsculas):\n");
            print_list(new_list);
        
            // Limpiar memoria
            ft_lstclear(&lst1, content_del);
            ft_lstclear(&new_list, content_del);
        
            return 0;
        }
        
        ```
### ***Parte 4 hacer el Makefile***

- **Makefile:**
    
    ```c
    # Nombre del ejecutable de la librería
    NAME = libft.a
    
    # Compilador y flags de compilación
    CC = gcc
    CFLAGS = -Wall -Werror -Wextra
    
    # Comando para crear la librería estática
    AR = ar rcs
    
    # Archivos fuente de la librería
    SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
           ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcpy.c \
           ft_strlen.c ft_strnstr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_memchr.c \
           ft_memcmp.c ft_strlcat.c ft_strncmp.c ft_strrchr.c ft_strdup.c ft_striteri.c \
           ft_strtrim.c ft_strjoin.c ft_itoa.c ft_putstr_fd.c ft_putendl_fd.c \
           ft_putchar_fd.c ft_putnbr_fd.c ft_strmapi.c ft_substr.c ft_split.c
    
    # Archivos fuente para el bonus
    BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
           ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
    
    # Objetos que se generan a partir de los archivos fuente
    OBJS = $(SRCS:.c=.o)
    BONUS_OBJS = $(BONUS_SRCS:.c=.o)
    
    # Reglas para compilar archivos .c a .o
    %.o: %.c
    	$(CC) $(CFLAGS) -c $< -o $@
    
    # Regla para crear la librería estática
    $(NAME): $(OBJS)
    	$(AR) $(NAME) $(OBJS)
    
    # Regla para compilar el bonus y agregar los objetos a la librería
    bonus: $(OBJS) $(BONUS_OBJS)
    	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
    
    # Regla por defecto: compilar todo
    all: $(NAME)
    
    # Limpiar los archivos .o
    clean:
    	rm -f $(OBJS) $(BONUS_OBJS)
    
    # Limpiar todo (archivos .o y el ejecutable)
    fclean: clean
    	rm -f $(NAME)
    
    # Recompilar desde cero
    re: fclean all
    
    # Declaración de reglas phony (no generan archivos)
    .PHONY: all clean fclean re bonus
    
    ```
    
- Explicación del código:
    
    ```c
    Explicación del Makefile:
    SRC: Esta variable contiene los archivos .c que forman parte de tu librería. Estos archivos se compilan en archivos objeto .o.
    OBJ: Se refiere a los archivos objeto generados a partir de los archivos fuente. Cada archivo .c se compila en un archivo .o correspondiente.
    LIBFT: Nombre del archivo de la librería estática que se generará (en este caso libft.a).
    MAIN: El archivo principal (main.c) que será compilado para probar tu librería.
    CFLAGS: Flags de compilación obligatorias para cumplir las reglas de Norminette (-Wall, -Werror, -Wextra).
    all: La regla por defecto que compila tanto la librería como el ejecutable.
    $(LIBFT): Compila los archivos fuente y genera la librería estática.
    $(NAME): Compila el archivo main.c enlazándolo con la librería libft.a.
    clean y fclean: Limpian los archivos objeto y el ejecutable/librería. fclean limpia todo, incluyendo el archivo de librería estática.
    re: Limpia y recompila todo desde cero.
    
    Paso 1: Compilar el proyecto
    Para compilar tu proyecto:
    
    Abre la terminal en el directorio del proyecto.
    Ejecuta el siguiente comando para compilar todo:
    make
    Esto generará un archivo ejecutable llamado test_libft y la librería libft.a.
    
    Paso 2: Limpiar el proyecto
    Si deseas limpiar los archivos objeto y el ejecutable/librería:
    
    make clean
    Para limpiar todo, incluidos los archivos objeto, el ejecutable y la librería:
    
    make fclean
    Paso 3: Recompilar el proyecto
    Si realizas cambios y deseas recompilar desde cero:
    
    make re
    Conclusión
    Este Makefile automatiza todo el proceso de compilación y te permite gestionar mejor los archivos objeto, la librería y el archivo de prueba main.c. Ahora puedes compilar y probar tu librería de manera eficiente.
    ```
    
- **Normas básicas**: Incluye las siguientes reglas en tu Makefile:
    - `all`: compilará tu proyecto completo.
    - `clean`: eliminará archivos objeto (.o) generados.
    - `fclean`: eliminará los archivos objeto y el ejecutable.
    - `re`: hará un `fclean` seguido de `all`.
    - `$(NAME)`: especifica el nombre del binario que vas a generar.
- **Compilación por pasos**: Si utilizas la libft, el Makefile debe compilar primero la librería usando su propio Makefile y luego compilar el resto del proyecto.
- **Evita relink**: Asegúrate de que tu Makefile solo relinkee los archivos modificados, no todo el proyecto, significa que no se puedan hacer un `make` y de nuevo otro `make`.
- **Valgrind**: Usa valgrind para asegurarte de que no haya fugas de memoria y de que la memoria dinámica se maneje correctamente.

### **Recomendaciones:**

### **Memoria Dinámica**

- **Gestión de memoria**: Cada vez que reserves memoria en el heap usando `malloc`, `calloc` o `realloc`, asegúrate de liberarla con `free`. Revisa el código usando herramientas como `valgrind` para verificar que no haya fugas de memoria.ls
- **Evitación de leaks**: Asegúrate de que cada función que reserva memoria se encargue de liberarla antes de finalizar o antes de asignar nueva memoria.
        
