# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 09:13:01 by vrandria          #+#    #+#              #
#    Updated: 2024/04/07 12:51:52 by vrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = main.c utils_pile.c utils_pile_2.c \
		ft_swap.c \
		ft_rotate.c ft_push.c ft_reverse_rotate.c  \
		ft_input.c check_errors.c \
		algorithme.c algo3.c find_value.c agorithime_utils.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap
CC = gcc

FLAGS = -Wall -Wextra -Werror
####################################################
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

####################################################
all: ${NAME}

####################################################
$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR) all --no-print-directory

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all --no-print-directory

####################################################
%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $?

$(NAME)	: $(OBJS)  $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(OBJS)  -o $(NAME) $(LIBFT) $(PRINTF) 

#####################################################
clean : 
		-rm -f ${OBJS}
		@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory
		@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
		-rm -f ${NAME}
		@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory
		@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re : fclean all

test :
#	./push_swap "1 2 3"
#	./push_swap "1 3 2"
#	./push_swap "3 1 2"
	./push_swap "358 195 391 25 -444 -128 -254 237 235 -304 487 -111 178 -78 -145 227 494 -463 -95 479 412 447 166 -306 200 396 58 281 171 75 138 -134 -345 353 -388 284 -402 40 20 24 -74 6 103 -397 119 458 330 112 185 -266 -220 97 371 136 -19 71 32 -462 -459 -298 -197 -131 -242 -41 -129 -258 -491 101 -48 -277 -474 327 -370 76 -26 150 378 -341 385 348 -54 -55 -16 427 206 -485 156 247 -283 459 306 -334 -393 217 37 -151 -83 -363 -9 140"
#	./push_swap "143 261 -367 113 -273 402 167 -344 453 204 -305 -53 174 -41 373 -463 -11 224 -87 413 393 -137 -384 219 -425 -40 -495 -302 237 -175 310 -121 -415 444 182 -497 345 -152 -341 -12 -448 -455 435 -84 -306 307 -47 184 30 57 -214 -388 420 -98 331 185 52 336 73 -211 352 -427 168 127 -484 -460 -180 51 -112 -20 -462 -370 -285 163 46 -91 190 -408 189 -254 -431 -9 356 -339 -178 -270 214 348 304 -498 -111 377 -140 207 83 -100 -474 289 -304 363 419 -89 25 -345 321 103 -437 281 172 55 136 334 67 366 -263 -396 -141 -261 -6 426 99 -300 8 500 -274 -168 -22 -77 -414 432 -156 -407 -34 448 -343 119 72 -358 159 -372 263 -13 -192 447 98 -354 111 97 133 265 -324 327 41 200 -264 -27 -456 -481 439 367 -315 -200 459 117 75 -298 -120 -438 11 -174 -335 -392 -337 -105 417 -401 350 283 116 -110 -18 42 -284 62 -8 398 -382 -133 389 -423 314 212 194 414 -359 -386 -410 497 -38 -193 360 -249 347 142 58 290 221 -149 -219 118 -30 148 47 -348 408 -260 322 -496 -128 126 -406 -132 39 228 20 346 87 -117 120 232 -48 -119 130 457 371 -399 -124 -80 -499 -296 31 242 -424 -292 -297 -374 -278 269 49 -470 368 191 -310 -49 320 -402 496 409 153 -398 -490 22 -327 -90 -83 205 141 -54 -93 -253 149 56 61 -176 112 382 -197 -28 -56 482 359 -268 478 267 385 -421 -33 -207 -209 -102 -155 -63 -19 251 -126 240 392 233 323 305 -240 218 484 -259 -316 -223 325 481 121 -486 248 -45 -379 -39 488 -229 -148 220 -55 397 88 -441 169 491 446 -287 2 -138 81 -108 -35 -258 416 140 -434 128 -378 -391 -153 54 434 449 252 -212 -266 239 424 40 -220 -208 50 -485 443 -32 188 -290 91 297 -3 -319 489 300 278 -31 202 387 201 -373 -4 -430 -118 -383 -157 351 -5 -257 -369 -10 -182 -479 -139 499 -491 -267 -60 129 108 -480 498 452 384 -67 293 -325 236 216 421 238 37 -289 355 -221 43 433 276 -51 358 480 -79 -71 -96 44 92 -439 89 10 324 48 -166 -409 -234 341 -172 -85 259 461 -413 -86 475 -233 302 -465 357 -307 -134 277 -357 -65 -390 354 273 -416 378 -418 -68 338 266 493 -403 18 -136 -262 -280 317 -64 -224 -281 -177 -447 258 407 474 100 195 464 -186 342 -422 -432 485 -376 418 -50 441 -146 227 403 -487 309 288 -277 -24 -352 -101 328 -477 -353 268 312 -312 -322 -472 280 193 -125 379 217 180 134 7"
#	./push_swap 17 -94 -1 56 78 -96 60 99 88 -16 79 -6 4 -62 70 -12 94 -89 5 -15 25 -86 -83 -20 -60 -21 97 -54 2 -77 32 -39 -63 -41 16 -64 -7 30 47 -17 71 90 -23 -25 -76 -98 81 -81 -22 -51 -93 -26 -74 -40 -52 59 -29 76 46 31 -9 82 74 36 21 -82 87 39 -36 -84 95 -92 86 -95 -66 64 11 -56 34 15 -53 -42 -34 6 -88 20 84 27 92 22 -18 96 -11 67 69 98 -19 -49 -44 37
#	./push_swap "5 1 2 8 0 4 7 3 6 9 5"
#	./push_swap "73 1 74 2 9 18 42 26 44 0 -1 21 84 -28 29 63 10 49 82"
#	./push_swap 0 53 14 78 35 60 3 46 89 12 67 70 45 99 50 23 1 58 36 79 5 93 18
#	./push_swap "73 96 18 55 37 68 21 84 29 63 10 49 82 6 91 27 42 53 14 78 35 60 3 46 89 12 67 24 57 39 81 19 75 8 61 32 94 15 70 45 99 50 23 64 1 58 36 79 5 93"
#	./push_swap "492 292 168 294 483 77 30 218 491 196 270 472 104 46 359 10 485 336 328 58 341 339 242 107 93 13 216 284 315 21 3 89 81 92 54 71 34 324 289 385 116 147 356 373 378 191 200 183 279 38 425 386 438 101 408 253 429 106 187 442 14 82 496 332 363 65 121 247 182 268 103 393 40 1 75 319 286 246 452 411 184 52 318 236 170 237 477 473 16 428 37 384 174 466 398 277 20 290 64 365"
#	./push_swap "64 47 6 28 21 30 74 99 76 61 72 50 87 71 20 43 45 53 17 97 38 70 46 98 79 86 52 41 78 24 63 25 27 35 82 88 40 33 10 39 49 31 22 60 81 92 16 19 15 55 56 65 26 75 91 23 68 77 89 62 95 80 42 29 66 69 54 83 73 8 11 9 96 13 44 48 93 2 3 94 51 57 90 18 12 85 37 5 59 67 7 84 36 32 14 58 34 4 100 1 -1"
.PHONY: printf
