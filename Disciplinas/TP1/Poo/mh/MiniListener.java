// Generated from Mini.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link MiniParser}.
 */
public interface MiniListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by the {@code Multiplicacao}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterMultiplicacao(MiniParser.MultiplicacaoContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Multiplicacao}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitMultiplicacao(MiniParser.MultiplicacaoContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Avaliar}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterAvaliar(MiniParser.AvaliarContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Avaliar}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitAvaliar(MiniParser.AvaliarContext ctx);
	/**
	 * Enter a parse tree produced by the {@code MenorIgual}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterMenorIgual(MiniParser.MenorIgualContext ctx);
	/**
	 * Exit a parse tree produced by the {@code MenorIgual}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitMenorIgual(MiniParser.MenorIgualContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Parenteses}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterParenteses(MiniParser.ParentesesContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Parenteses}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitParenteses(MiniParser.ParentesesContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Load}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterLoad(MiniParser.LoadContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Load}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitLoad(MiniParser.LoadContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Or}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterOr(MiniParser.OrContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Or}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitOr(MiniParser.OrContext ctx);
	/**
	 * Enter a parse tree produced by the {@code True}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterTrue(MiniParser.TrueContext ctx);
	/**
	 * Exit a parse tree produced by the {@code True}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitTrue(MiniParser.TrueContext ctx);
	/**
	 * Enter a parse tree produced by the {@code False}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterFalse(MiniParser.FalseContext ctx);
	/**
	 * Exit a parse tree produced by the {@code False}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitFalse(MiniParser.FalseContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Subtracao}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterSubtracao(MiniParser.SubtracaoContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Subtracao}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitSubtracao(MiniParser.SubtracaoContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Divisao}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterDivisao(MiniParser.DivisaoContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Divisao}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitDivisao(MiniParser.DivisaoContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Not}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterNot(MiniParser.NotContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Not}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitNot(MiniParser.NotContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Maior}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterMaior(MiniParser.MaiorContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Maior}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitMaior(MiniParser.MaiorContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Menor}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterMenor(MiniParser.MenorContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Menor}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitMenor(MiniParser.MenorContext ctx);
	/**
	 * Enter a parse tree produced by the {@code And}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterAnd(MiniParser.AndContext ctx);
	/**
	 * Exit a parse tree produced by the {@code And}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitAnd(MiniParser.AndContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Soma}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterSoma(MiniParser.SomaContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Soma}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitSoma(MiniParser.SomaContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Igual}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterIgual(MiniParser.IgualContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Igual}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitIgual(MiniParser.IgualContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Let}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterLet(MiniParser.LetContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Let}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitLet(MiniParser.LetContext ctx);
	/**
	 * Enter a parse tree produced by the {@code MaiorIgual}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterMaiorIgual(MiniParser.MaiorIgualContext ctx);
	/**
	 * Exit a parse tree produced by the {@code MaiorIgual}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitMaiorIgual(MiniParser.MaiorIgualContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Identificador}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterIdentificador(MiniParser.IdentificadorContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Identificador}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitIdentificador(MiniParser.IdentificadorContext ctx);
	/**
	 * Enter a parse tree produced by the {@code If}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterIf(MiniParser.IfContext ctx);
	/**
	 * Exit a parse tree produced by the {@code If}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitIf(MiniParser.IfContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Inteiro}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void enterInteiro(MiniParser.InteiroContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Inteiro}
	 * labeled alternative in {@link MiniParser#expressao}.
	 * @param ctx the parse tree
	 */
	void exitInteiro(MiniParser.InteiroContext ctx);
}